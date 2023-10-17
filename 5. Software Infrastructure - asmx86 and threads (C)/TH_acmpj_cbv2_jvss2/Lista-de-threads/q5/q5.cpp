//Sendo uma mesa redonda com cinco grafos e cinco pratos e uma tigela de macarrao   
//Sendo os garfos recursos compartilhados e os filósofos threads
//Todos os filosofos precisam comer e para isso utiliza os dois garfos adjacentes
//          Somente um filósofo pode usar um garfo por vez;
//          Deadlock não pode ocorrer;
//          Starvation não pode acontecer;
//          Mais de um filósofo pode comer ao mesmo tempo;
//          Permitir o máximo de concorrência possível;
//          Não precisa se preocupar em relação ao tempo para comer, mas o filósofo precisa terminar de se alimentar em algum momento.

//Para rodar:
//Terminal estando aberto na pasta Lista-de-threads, insira:
// - cd q5
// - g++ -pthread q5.cpp -o q5
// - ./q5

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>     //Biblioteca de threads
#include <unistd.h>

#define QNT_THREADS 5    //Quantidades de threads
#define QNT_GARFOS 5     //Quantidades de garfos

pthread_mutex_t *mutex;  //Mutex para cada garfo (sera alocado dinamicamente)

void *pegarMacarrao(void *arg){

    while(true){ //Ao acabar de comer, tenta comer novamente (Fonte infinita de macarrao, codigo nao termina)

        int *garfo = (int *)arg, proxGarfo = (*garfo) + 1;    //O filosofo 0 pegara o garfo 0 e 1, por isso o id é passado como argumento para definir os garfos que serao usados 
        if(proxGarfo == 5) proxGarfo = 0;                     //No caso do filosófo 4, ele pega o garfo 4 e 0 (nao ha garfo 5 e eh uma mesa redonda)   
        sleep(1);       //think();
        //Para que não haja deadlock, eh necessario definir alguma condicao na hora de pegar os garfos
        //A escolhida foi:
        //  se o id do filosofo (que eh igual ao valor do primeiro garfo que ele pega) for par, ele pega o primeiro garfo e depois o proximo garfo
        //  Já se for impar, ele paga o proximo garfo e depois o primeiro garfo
        if(*garfo % 2){
            pthread_mutex_lock(&mutex[proxGarfo]);     //Trava o mutex do proximo garfo para que nenhum outro filosofo pegue
            pthread_mutex_lock(&mutex[*garfo]);        //Trava o mutex do primeiro garfo (quando estiver livre, ja que pode estar travado por outro filosofo comendo mas sera destravado em breve)
            printf("Filósofo %d começou a comer. Garfos %d e %d sendo utilizados.\n", *garfo, *garfo, proxGarfo);
            sleep(1);      //Filosofo comendo
            printf("Filósofo %d acabou de comer. Garfos %d e %d liberados.\n", *garfo, *garfo, proxGarfo);
            pthread_mutex_unlock(&mutex[*garfo]);     //Acabou de comer, entao libera o mutex
            pthread_mutex_unlock(&mutex[proxGarfo]);  //Acabou de comer, entao libera o mutex
        }else{
            pthread_mutex_lock(&mutex[*garfo]);       //Trava o mutex do primeiro garfo para que nenhum outro filosofo pegue
            pthread_mutex_lock(&mutex[proxGarfo]);    //Trava o mutex do primeiro garfo (quando estiver livre, ja que pode estar travado por outro filosofo comendo mas sera destravado em breve)
            printf("Filósofo %d começou a comer. Garfos %d e %d sendo utilizados.\n", *garfo, *garfo, proxGarfo);
            sleep(1);      //Filosofo comendo
            printf("Filósofo %d acabou de comer. Garfos %d e %d liberados.\n", *garfo, *garfo, proxGarfo);
            pthread_mutex_unlock(&mutex[proxGarfo]); //Acabou de comer, entao libera o mutex
            pthread_mutex_unlock(&mutex[*garfo]);    //Acabou de comer, entao libera o mutex
        }
    }
} 

int main() {

    pthread_t threads[QNT_THREADS];     //Declara quantas threads serao criadas

    mutex = (pthread_mutex_t *)malloc((QNT_GARFOS) * sizeof(pthread_mutex_t));      //Aloca dinamicamente o vetor de mutex (precisa ter o tamanho do numero de garfos)
    for(int i = 0; i < QNT_GARFOS; i++) mutex[i] = PTHREAD_MUTEX_INITIALIZER;

    int ids[QNT_THREADS]; //Vetor de ID's da threads

    for(int i = 0; i < QNT_THREADS; i++){
        ids[i] = i; //Define o ID
        if(pthread_create(&threads[i], NULL, &pegarMacarrao, (void *)&ids[i])){ //Cria a thread e passando a função 'pegarMacarrao' como parâmetro e o ID da thread como argumento
            perror("Failed to create thread");      //Verifica se houve erro na criaçao da thread
        }
    }

    for(int i = 0; i < QNT_THREADS; i++){ //Join em todas as Threads que já foram criadas
        if(pthread_join(threads[i], NULL) != 0){    //Join em todas as threads criadas
            perror("Failed to join thread");       //Verifica se houve erro no join
        }
    }

    free(mutex);    //Free no mutex que foi alocado dinamicamente
    pthread_exit(NULL);     //Encerra a thread (main)
}