#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool primo(int num) {
    int i;
    for (i=2; i <= num/2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

bool valid(vector<int> & array, int N, int qtd) {
    int i=1, j=0;
    
    for (i=0; i<qtd-1; i++) {
        if (array[i] == array[qtd-1]) return false;
    }
    
    while (array[i] != 0 && i<N) {
        if (!primo(array[i]+array[i-1])) return false;
        i++;
    }
    /*for (i=0; i<N-1 && array[i] != 0; i++) {
        for (j=i+1; j<N &&array[j] != 0; j++) {
            if (array[i] == array[j]) return false;
        }
    }*/
    if (!primo(array[0] + array[N-1])) return false;
    return true;
}

void printArray(vector<int> & array, int N) {
    int i, flag=0;
    for (i=0; i<N; i++) {
        if (flag == 1) printf(" ");
        printf("%d", array[i]);
        flag = 1;
    }
    printf("\n");
    return;
}

void primeRing(vector<int> & array, int N, int qtd) {
    if (qtd == N) {
        if (valid(array, N, qtd)) {
            printArray(array, N);
        }
        return;
    }
    for (int i=1; i<N+1; i++) {
        if (valid(array, N, qtd)) {
            array[qtd] = i;
            qtd++;
            primeRing(array, N, qtd);
            qtd--;
            array[qtd] = 0;
        }
    }
}

int main() {
    int N, qtd=1, caso=1, flag=0;
    while (scanf("%d", &N) != EOF) {
        if (N<17) {
            if (flag == 1) printf("\n");
            printf("Case %d:\n", caso);
            qtd = 1;
            vector<int> array(N);
            array[0] = 1;
            primeRing(array, N, qtd);
            caso++;
            flag = 1;
        }
    }
    return 0;
}