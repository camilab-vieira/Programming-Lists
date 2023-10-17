//Uma matriz quadrada é considerada um quadrado latino se um simbolo aparece somente uma vez em uma linha ou coluna.


//Para rodar:
//Terminal estando aberto na pasta Lista-de-threads, insira:
// - cd q7
// - g++ -pthread q7.cpp -o q7
// - ./q7
//
//Casos Teste (copiar e colar no terminal apos rodar o programa)
//Primeiro digito representa o tamanho da matriz e os seguintes, os elementos da matriz
//   4 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -> Eh um Quadrado Latino
//   3 2 4 6 3 6 9 4 8 12 -> Eh um Quadrado Latino
//   2 1 1 0 0 -> Nao eh um Quadrado Latino
//   2 1 0 1 2 -> Nao eh um Quadrado Latino

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>     //Biblioteca de threads

pthread_mutex_t mutexVerificacao = PTHREAD_MUTEX_INITIALIZER;    //Mutex para alterar se ehQuadradoLatino (recurso compartilhado)


int tam;
bool ehQuadradoLatino = true;
int** Matriz;

void *verificarPosicoes(void *arg){

    int *id = (int *)arg;
    int posVertical = *id / tam, posHorizontal = *id % tam;;
    bool haElementosIguais = false;

    for(int i = 0; i < tam && !(haElementosIguais); i++){   //Verifica se ha algum outro elemento igual a este na coluna ou linha
        if(Matriz[posVertical][posHorizontal] == Matriz[i][posHorizontal]){ if (i != posVertical) haElementosIguais = true;}
        if(Matriz[posVertical][posHorizontal] == Matriz[posVertical][i]){ if (i != posHorizontal) haElementosIguais = true;}
    }  

    if(haElementosIguais){                          //Se houver um elemento igual, nao eh quadrado latino, eh preciso alterar a variavel ehQuadradoLatino
        pthread_mutex_lock(&mutexVerificacao);      //Travamos o mutex para acessar um recurso compartilhado
        ehQuadradoLatino = false;                   //Altera a variavel
        pthread_mutex_unlock(&mutexVerificacao);    //Apos alterar, destrava o mutex 
    }  

    pthread_exit(NULL);     //Encerra a thread
}

int main(){

    printf("Insira o tamanho da matriz: ");
    scanf(" %d", &tam);
    Matriz = (int**)malloc(sizeof(int*)*tam);       //Aloca a matriz
    for(int i = 0; i < tam; i++) Matriz[i] = (int*)malloc(sizeof(int)*tam);
    
    printf("Insira a matriz: \n");
    for(int i = 0; i < tam; i++){for(int j = 0; j < tam; j++) scanf(" %d", &Matriz[i][j]);}     //Ler a matriz


    int qntThreads = tam*tam;
    pthread_t threads[qntThreads];      //Declara quantas threads serao criadas

    int ids[qntThreads];       //Vetor de IDs das threads

    for(int i = 0; i < qntThreads; i++){
        ids[i] = i;     //Define o id da thread
        if(pthread_create(&threads[i], NULL, &verificarPosicoes, (void *)&ids[i])){ //Cria a thread e passa a função 'verificarPosicoes' como parâmetro e o ID da Thread como argumento
            perror("Failed to create thread");      //Verifica se houve erro na criaçao da thread
        }
    }

    for(int i = 0; i < qntThreads; i++){
        if(pthread_join(threads[i], NULL) != 0){    //Join em todas as threads criadas
            perror("Failed to join thread");       //Verifica se houve erro no join
        }
    }
    
    if(ehQuadradoLatino) printf("Eh um Quadrado Latino\n");     //Verifica se eh ou nao quadrado latino
    else printf("Nao eh um Quadrado Latino\n");

    for(int i = 0; i < tam; i++) free(Matriz[i]);   //Free matriz
    free(Matriz);       
    
    pthread_exit(NULL);     //Encerra a thread (main)
}
