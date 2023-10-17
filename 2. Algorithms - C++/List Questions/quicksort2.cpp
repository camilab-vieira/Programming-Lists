#include <iostream>

int HoarePartition(int A[], int l, int r){
    int p = A[l], i = l, j = (r + 1), temp;
    do{
        do{i++;}
        while(A[i] < p && i < r);
        do{j--;}
        while(A[j] > p);
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }while(i < j);
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(A, l, r);
        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);
    }
}

int main(){
    int i, qntChoc, qntCupom;
    unsigned long long valor, soma = 0;
    scanf("%d", &qntChoc);
    int choc[qntChoc];
    for(i = 0; i < qntChoc; i++){scanf("%d", &choc[i]); soma += choc[i];}
    quicksort(choc, 0, qntChoc - 1);
    scanf("%d", &qntCupom);
    int cupom[qntCupom];
    for(i = 0; i < qntCupom; i++){ 
        scanf("%d", &cupom[i]);
        valor = qntChoc - cupom[i]; 
        valor = soma - choc[valor];
        printf("%llu\n", valor);
    }
}