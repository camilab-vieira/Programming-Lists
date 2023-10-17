//Esse programa simula um sistema computacional de controle de ferrovias composta por cinco intersecoes que permitem dois trens simultaneamente
//A passagem de um trem dura 500 milissegundos
//Assumir a existencia de dez trens (representados por uma thread) que devem percorrer a intersecao 1 a 5 em ordem e recomecar

//Para rodar:
//Terminal estando aberto na pasta Lista-de-threads, insira:
// - cd q2
// - g++ -pthread q2.cpp -o q2
// - ./q2

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>             //Biblioteca de threads

#define QNT_INTERSECCOES 5      //Quantidades de interseccoes
#define QNT_THREADS 10          //Quantidades de threads

pthread_mutex_t *mutex;        //Mutex para cada intersecao (sera alocado dinamicamente) 
pthread_cond_t *cond;          //Variavel de condicao para cada intersecao (sera alocado dinamicamente) 

int interseccoes[QNT_INTERSECCOES] = {0};           //Intersecoes (o valor representa a quantidade de trens passando)

void passagemInterseccao(int id, int numInterseccao){
    pthread_mutex_lock(&mutex[numInterseccao]);     //Trava o mutex da interseccao para entrar nela (garantir que nao havera conflito)
        while(interseccoes[numInterseccao] >= 2)    //Verifica se ha espaço na interseccao (se houver dois ou mais trens sera necessario esperar)
            pthread_cond_wait(&cond[numInterseccao], &mutex[numInterseccao]);       //Variavel de condicao, enquanto a condicao nao for atendida, espera
        
        interseccoes[numInterseccao]++;             //Se conseguiu entrar, incrementa o valor (ha um trem a mais na interseccao)
        printf("O trem %d começou a passar pela interseccao %d.\n", id, numInterseccao + 1);
            if(interseccoes[numInterseccao] == 2) printf("Dois trens estao passando pela interseccao %d.\n", numInterseccao + 1);
            if(interseccoes[numInterseccao] > 2) printf("ERRO: Mais de dois trens estao passando pela interseccao %d.\n", numInterseccao + 1);
    pthread_mutex_unlock(&mutex[numInterseccao]);   //Destrava o mutex, a interseccao volta a ser livre para ser acessada por outra thread

    std::this_thread::sleep_for(std::chrono::milliseconds(500));    //Tempo de passagem pela intersecao

    pthread_mutex_lock(&mutex[numInterseccao]);     //Trava o mutex da interseccao para entrar nela (garantir que nao havera conflito)
        interseccoes[numInterseccao]--;             //Saiu, entao decrementa a quantidade de trens na interseccao
        printf("O trem %d acabou de passar pela interseccao %d.\n", id, numInterseccao + 1);
        if(interseccoes[numInterseccao] == 1) pthread_cond_signal(&cond[numInterseccao]);   //Manda o signal para alertar um trem esperando
    pthread_mutex_unlock(&mutex[numInterseccao]);   //Destrava o mutex, a interseccao volta a ser livre para ser acessada por outra thread
}

void *controleFerrovia(void *arg){
    int id = *(int *)arg + 1;               //Define o trem que esta passando
    while(true){                            //Ao terminar devera trafegar novamente
        for(int i = 0; i < QNT_INTERSECCOES; i++){
            passagemInterseccao(id, i);     //Manda passar o trem controlado pela thread passar pela proxima interseccao do percuso
        }
    }
} 

int main() {
    pthread_t threads[QNT_THREADS];     //Declara quantas threads serao criadas
    
    mutex = (pthread_mutex_t *)malloc((QNT_INTERSECCOES) * sizeof(pthread_mutex_t));      //Aloca dinamicamente o vetor de mutex (precisa ter o tamanho do numero de interseccoes)
    for(int i = 0; i < QNT_INTERSECCOES; i++) mutex[i] = PTHREAD_MUTEX_INITIALIZER;
    
    cond = (pthread_cond_t *)malloc((QNT_INTERSECCOES) * sizeof(pthread_cond_t));        //Aloca dinamicamente o vetor de variaveis de condicao (precisa ter o tamanho do numero de interseccoes)
    for(int i = 0; i < QNT_INTERSECCOES; i++) cond[i] = PTHREAD_COND_INITIALIZER;
   
    int ids[QNT_THREADS];       //Vetor de IDs das threads

    for(int i = 0; i < QNT_THREADS; i++){
        ids[i] = i;     //Define o id da thread
        if(pthread_create(&threads[i], NULL, &controleFerrovia, (void *)&ids[i])){ //Cria a thread e passa a função 'controleFerrovia' como parâmetro e o ID da Thread como argumento
            perror("Failed to create thread");      //Verifica se houve erro na criaçao da thread
        }
    }

    for(int i = 0; i < QNT_THREADS; i++){ 
        if(pthread_join(threads[i], NULL) != 0){    //Join em todas as threads criadas
            perror("Failed to join thread");       //Verifica se houve erro no join
        }
    }

    free(mutex);    //Free no mutex que foi alocado dinamicamente
    free(cond);     //Free na variavel de condicao que foi alocada dinamicamente
    pthread_exit(NULL);     //Encerra a thread (main)
}