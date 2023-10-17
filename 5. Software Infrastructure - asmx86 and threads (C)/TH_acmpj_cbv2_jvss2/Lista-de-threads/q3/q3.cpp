//Esse programa simula um sistema de gerenciamento de banco de dados
//Threads escritoras deverão continuamente escrever no array em qualquer posicao 
//Threads leitoras deverão ler dados (de forma contínua) de  qualquer posicao
//Thread leitora não bloqueia outra thread leitora
//Thread escritora deverá bloquear todas as outras (escritoras e leitoras) que desejarem acessar o recurso compartilhado

//Para rodar:
//Terminal estando aberto na pasta Lista-de-threads, insira:
// - cd q3
// - g++ -pthread q3.cpp -o q3
// - ./q3

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>    //Biblioteca de threads
#include <unistd.h>     //Biblioteca para usar sleep

#define QNT_THREADS_LEITORAS 10     //Quantidades de threads leitoras
#define QNT_THREADS_ESCRITORAS 5    //Quantidades de threads escritoras
#define TAM_BANCO 3                 //Tamanho do banco de dados

pthread_mutex_t *mutex;             //Mutex para cada posicao do array do banco de dados (sera alocado dinamicamente) 
pthread_cond_t *condLeitura;        //Variavel de condicao para realizar leitura para cada posicao do array do banco de dados (sera alocado dinamicamente) 
pthread_cond_t *condEscrita;        //Variavel de condicao para realizar escrita para cada posicao do array do banco de dados (sera alocado dinamicamente) 

int BANCO_DE_DADOS[TAM_BANCO];
int lendo[TAM_BANCO] = {0};
int fila_de_espera_escrita[TAM_BANCO] = {0};
bool escrevendo[TAM_BANCO] = {false};

void *escrita(void *arg){
    int id = *(int *)arg, pos = id;
    while(true){    
        pos = ((pos*13) + 17)%TAM_BANCO;    //Pega uma posicao de forma pseudoaleatoria
        
        pthread_mutex_lock(&mutex[pos]);    //Trava o mutex para garantir acesso aos recurso compartilhados da posicao (regiao critica) por apenas uma thread
            fila_de_espera_escrita[pos]++;  //Ha mais uma thread querendo escrever
            while(escrevendo[pos] || lendo[pos]){   //Enquanto houver alguma thread lendo ou escrevendo, precisa esperar para poder escrever (variavel de condicao)
                printf("A thread %d esta esperando para realizar escrita na posicao %d\n", id, pos);
                pthread_cond_wait(&condEscrita[pos], &mutex[pos]);  
            }
            escrevendo[pos] = true;         //As condiçoes para ocorrer escrita foram encotradas, esta thread estara escrevendo nesta posicao
        pthread_mutex_unlock(&mutex[pos]);  //Destrava mutex
        
        printf("A thread %d esta realizando escrita na posicao %d\n", id, pos);
        sleep(2); //Simula o processo de escrita

        pthread_mutex_lock(&mutex[pos]);  //Trava o mutex para garantir acesso aos recurso compartilhados da posicao (regiao critica) por apenas uma thread
            escrevendo[pos] = false;      //Esta thread nao mais esta escrevendo
            fila_de_espera_escrita[pos]--; //Menos uma thread querendo escrever
            pthread_cond_signal(&condEscrita[pos]); //Avisar a variavel de condicao da escrita que estava aguardando pelo fim para escrever (verificar se agora eh possivel)
            pthread_cond_signal(&condLeitura[pos]); //Avisar a variavel de condicao da escrita que estava aguardando pelo fim para ler (verificar se agora eh possivel)
        pthread_mutex_unlock(&mutex[pos]); //Destrava o mutex
    }
}
void *leitura(void *arg){
    int id = *(int *)arg, pos = id;
    while(true){    
        pos = ((pos*7) + 19)%TAM_BANCO;     //Pega uma posicao de forma pseudoaleatoria

        pthread_mutex_lock(&mutex[pos]);    //Trava o mutex para garantir acesso aos recurso compartilhados da posicao (regiao critica) por apenas uma thread
            while(escrevendo[pos] || fila_de_espera_escrita[pos] >= 2){ //Enquanto houver alguma thread escrevendo ou muitas esperando para escrever (na fila de espera), precisa esperar para poder ler (variavel de condicao)
                printf("A thread %d esta esperando para realizar leitura na posicao %d\n", id, pos);
                pthread_cond_wait(&condLeitura[pos], &mutex[pos]);
            }
            lendo[pos]++;                   //Ha mais uma thread lendo
            if(lendo[pos] > 1) printf("%d thread estao realizando leitura na posicao %d\n", lendo[pos], pos);
        pthread_mutex_unlock(&mutex[pos]);  //Destrava o mutex
        
        printf("A thread %d esta realizando leitura na posicao %d\n", id, pos);
        sleep(2);   //Simboliza o processo de leitura

        pthread_mutex_lock(&mutex[pos]);    //Trava o mutex para garantir acesso aos recurso compartilhados da posicao (regiao critica) por apenas uma thread
            lendo[pos]--;                   //Ha uma thread a menos lendo
            if(lendo[pos] == 0) pthread_cond_signal(&condEscrita[pos]); //Avisar a variavel de condicao da escrita que estava aguardando pelo fim para escrever (verificar se agora eh possivel)
        pthread_mutex_unlock(&mutex[pos]);  //Destrava o mutex
    }
}

int main() {
    pthread_t threadsLeitoras[QNT_THREADS_LEITORAS];        //Declara quantas threads de leitura serao criadas
    pthread_t threadsEscritoras[QNT_THREADS_ESCRITORAS];    //Declara quantas threads de escrita serao criadas
    
    mutex = (pthread_mutex_t *)malloc((TAM_BANCO) * sizeof(pthread_mutex_t));           //Aloca dinamicamente o vetor de mutex (precisa ter o tamanho do numero de posicoes do banco de dados)
    for(int i = 0; i < TAM_BANCO; i++) mutex[i] = PTHREAD_MUTEX_INITIALIZER;

    condLeitura = (pthread_cond_t *)malloc((TAM_BANCO) * sizeof(pthread_cond_t));       //Aloca dinamicamente o vetor de variaveis de condicao de leitura (precisa ter o tamanho do numero de posicoes do banco de dados)
    for(int i = 0; i < TAM_BANCO; i++) condLeitura[i] = PTHREAD_COND_INITIALIZER;

    condEscrita = (pthread_cond_t *)malloc((TAM_BANCO) * sizeof(pthread_cond_t));       //Aloca dinamicamente o vetor de variaveis de condicao de escrita (precisa ter o tamanho do numero de posicoes do banco de dados)
    for(int i = 0; i < TAM_BANCO; i++) condEscrita[i] = PTHREAD_COND_INITIALIZER;
    
    int idsLeitora[QNT_THREADS_LEITORAS];           //Vetor de ID's da threads de leitura
    int idsEscritora[QNT_THREADS_ESCRITORAS];       //Vetor de ID's da threads de escrita

    for(int i = 0; i < QNT_THREADS_LEITORAS; i++){
        idsLeitora[i] = i;      //Define o ID
        if(pthread_create(&threadsLeitoras[i], NULL, &leitura, (void *)&idsLeitora[i])){ //Cria a thread e passando a função 'leitura' como parâmetro e o ID da thread como argumento
            perror("Failed to create thread");      //Verifica se houve erro na criaçao da thread
        }
    }

    for(int i = 0; i < QNT_THREADS_ESCRITORAS; i++){
        idsEscritora[i] = i;    //Define o ID
        if(pthread_create(&threadsEscritoras[i], NULL, &escrita, (void *)&idsEscritora[i])){ //Cria a thread e passando a função 'escrita' como parâmetro e o ID da thread como argumento
            perror("Failed to create thread");      //Verifica se houve erro na criaçao da thread
        }
    }

    for(int i = 0; i < QNT_THREADS_LEITORAS; i++){
        if(pthread_join(threadsLeitoras[i], NULL) != 0){    //Join em todas as threads criadas
            perror("Failed to join thread");       //Verifica se houve erro no join
        }
    }

    for(int i = 0; i < QNT_THREADS_ESCRITORAS; i++){
        if(pthread_join(threadsEscritoras[i], NULL) != 0){    //Join em todas as threads criadas
            perror("Failed to join thread");       //Verifica se houve erro no join
        }
    }

    free(mutex);    //Free no mutex que foi alocado dinamicamente
    pthread_exit(NULL);     //Encerra a thread (main)
}
