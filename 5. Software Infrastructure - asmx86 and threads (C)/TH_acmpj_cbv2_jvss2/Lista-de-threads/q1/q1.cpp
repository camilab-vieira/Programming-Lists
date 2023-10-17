//Esse programa simula um sistema eletronico de votação. Cada arquivo representa os votos de determinado bairro. 
//Cada linha do arquivo conta com o numero do candidato que recebeu o voto (zero corresponde a branco).
//Cada arquivo sera lido por uma thread que ira contabilizar os votos 
//Garantindo exclusao mutua ao alterar o numero de votos em uma posicao

//Para rodar:
//Terminal estando aberto na pasta Lista-de-threads, insira:
// - cd q1
// - g++ -pthread q1.cpp -o q1
// - ./q1

//Output esperado:
// Total de votos: 95
// Votos em branco: 14.74%
// Votos em 1: 7.37%
// Votos em 2: 11.58%
// Votos em 3: 21.05%
// Votos em 4: 12.63%
// Votos em 5: 11.58%
// Votos em 6: 12.63%
// Votos em 7: 8.42%
// O vencedor foi 3 com 21.05% dos votos (20 votos).

//Em 1.in ha 25 votos, 2.in ha 18 votos, 3.in ha 11 votos, 4.in ha 11 votos, 5.in ha 30 votos.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>         //Biblioteca de threads

#define QNT_ARQUIVOS 5      //Quantidades de arquivos que serao lidos (N)
#define QNT_THREADS 3       //Quantidades de threads (T)
#define QNT_CANDIDATOS 7    //Quantidades de candidatos (Y)

pthread_mutex_t *mutexArrayVotos;   //Mutex para cada posicao do array de votos (sera alocado dinamicamente) -> exclusao mutua para cada posicao do array.
pthread_mutex_t mutexArq = PTHREAD_MUTEX_INITIALIZER;   //Mutex para alterar a quantidade de arquivos abertos e assim definir qual o proximo arquivo deve ser lido -> quando a thread termina a leitura pega outro nao lido dinamicamente
pthread_mutex_t mutexTotalVotos = PTHREAD_MUTEX_INITIALIZER;    //Mutex para alterar a quantidade total de votos (sera util no fim do codigo para fazer as operacoes de porcentagem)

int arquivosAbertos = 0;
bool restaArquivos = true;
float totalVotos = 0;
float votos[QNT_CANDIDATOS + 1];    //Neste array sera armazenado a quantidade de votos por candidato

void *contarVotos(void *arg){

    char nomeDoArquivo[10];
    int voto;

    while(restaArquivos){    //Ennquanto restar algum arquivo para ser lido, a thread continua a realizar a tarefa
        pthread_mutex_lock(&mutexArq);       //Trava o mutex para outras threads nao acessarem a quantidade de arquivos abertos e assim definir qual sera o proximo arquivo que sera lido (evita condição de disputa e garante que uma unica thread tenha acesso a um arquivo)
        if(arquivosAbertos < QNT_ARQUIVOS){ //Verifica se todos os arquivos ja foram lidos
            arquivosAbertos++;             //Aumenta a quantidade de arquivos que foram abertos
            sprintf(nomeDoArquivo, "%d.in", arquivosAbertos);   //Define o nome do arquivo que sera aberto (nome do arquivo eh dado por "x.in" | 1 <= x <= N (qtd de arquivos))
            pthread_mutex_unlock(&mutexArq);    //Thread já acabou de definir o arquivo que irá processar, pode liberar o mutex. 
            //A variavel arquivosAbertos eh a regiao critica, pois a partir dela sera definido o nome do arquivo que sera aberto
        }else{      //Se nenhum arquivo mais sera aberto, a thread define restaArquivos como falso (para que as outras nao continue), destrava o mutex e encerra a thread
            restaArquivos = false;
            pthread_mutex_unlock(&mutexArq);
            pthread_exit(NULL);
        }

        FILE *arquivo;      //Para abrir o arquivo de acordo com o nome do arquivo que foi estabelecido anteriormente
        if((arquivo = fopen(nomeDoArquivo, "r")) == NULL){
            printf("Nao foi possivel abrir o arquivo!\n");
            exit(-1);
        } 

        float totalVotosArq = 0; //variavel local para contar apenas os votos do arquivo que esta sendo processado

        while((fscanf(arquivo, "%d", &voto)) != EOF){ //Ler os votos do arquivo
            totalVotosArq++;    //Incrementar a quantidade de votos do arquivo processado
            pthread_mutex_lock(&mutexArrayVotos[voto]);     //Trava o mutex da posicao em que sera incrementado o voto para nao haver conflito com outras threads
            votos[voto]++;      //Incrementa o voto na posicao correspondente do candidato
            pthread_mutex_unlock(&mutexArrayVotos[voto]);   //Destrava o mutex apos incrementar o voto para que outras threads possam acessar
        }

            //Apos acabar a leitura dos votos, soma a quantidade de votos do arquivo processado a quantidade de votos ao todo
            pthread_mutex_lock(&mutexTotalVotos);   //Trava o mutex para outras threads nao acessarem totalVotos (um recurso compartilhado)
            totalVotos += totalVotosArq;
            pthread_mutex_unlock(&mutexTotalVotos);     //Destrava o mutex apos incrementar
        fclose(arquivo);    //Fecha o arquivo
    }
    pthread_exit(NULL);     //Encerra a thread
} 

int main() {

    pthread_t threads[QNT_THREADS];     //Declara quantas threads serao criadas
    
    mutexArrayVotos = (pthread_mutex_t *)malloc((QNT_CANDIDATOS+1) * sizeof(pthread_mutex_t));      //Aloca dinamicamente o vetor de mutex (precisa ter o tamanho do numero de candidatos mais um (voto em branco))
    for(int i = 0; i <= QNT_CANDIDATOS; i++) mutexArrayVotos[i] = PTHREAD_MUTEX_INITIALIZER;

    for(int i = 0; i <= QNT_CANDIDATOS; i++) votos[i] = 0;      //Zera a quantidade de votos na array de votos
   
    for(int i = 0; i < QNT_THREADS; i++){
        if(pthread_create(&threads[i], NULL, &contarVotos, NULL)){ //Cria a thread e passa a função 'contarVotos' como parâmetro, sem argumento
            perror("Failed to create thread");      //Verifica se houve erro na criaçao da thread
        }
    }

    for(int i = 0; i < QNT_THREADS; i++){ 
        if(pthread_join(threads[i], NULL) != 0){    //Join em todas as threads criadas
            perror("Failed to join thread");       //Verifica se houve erro no join
        }
    }

    printf("Total de votos: %.0f\n", totalVotos);   //Printa o total de votos
    
    printf("Votos em branco: %.2f%c\n", (votos[0]/totalVotos)*100, 37); //Printa a qtd de votos em branco

    float max = 0;
    int eleito = 1;
    for(int i = 1; i <= QNT_CANDIDATOS; i++){
        if(votos[i] > max){     //Define o mais votado
            max = votos[i];     
            eleito = i;         
        }
        printf("Votos em %d: %.2f%c\n", i, (votos[i]/totalVotos)*100, 37);    //Printa em porcentagem os votos de cada candidato em porcentagem
    }
    
    printf("O vencedor foi %d com %.2f%c dos votos (%.0f votos).\n", eleito, (max/totalVotos)*100, 37, max);    //Printa o vencedor com a sua porcentagem de votos

    free(mutexArrayVotos);   //Free no mutex que foi alocado dinamicamente
    pthread_exit(NULL);     //Encerra a thread (main)
}