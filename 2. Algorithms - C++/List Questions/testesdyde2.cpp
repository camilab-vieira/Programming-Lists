#include <iostream>
#include <stdio.h>

bool isPrime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};


void printRing(int ring[20], int ringSize){
    printf("1");
    for(int i = 1; i < ringSize; i++){
        printf(" %d", ring[i]);
    }
    printf("\n");
}

void primeRing(int current,int ring[20], bool usedNumbers[20], int ringSize){
    if(current == ringSize){
        if(isPrime[1 + ring[ringSize-1]]){
            printRing(ring, ringSize);
        } else {
            return;
        }
    }

    for(int i = 2; i < ringSize+1; i++){
        if(usedNumbers[i]) 
            continue;
        if(isPrime[ring[current - 1] + i]){
            ring[current] = i;
            usedNumbers[i] = true;
            primeRing(current+1, ring, usedNumbers, ringSize);
            usedNumbers[i] = 0; //faz o backtrack
        }
    }
}

int main(void){
    int numRing;
    int currCase = 1;

    while(scanf("%d", &numRing) != EOF){
        int ring[20];
        bool usedNumbers[20] = {0};
        ring[0] = 1;

        if(currCase != 1)
            printf("\n");
        printf("Case %d:\n", currCase++);
        primeRing(1, ring, usedNumbers, numRing);
    }

    return 0;
}