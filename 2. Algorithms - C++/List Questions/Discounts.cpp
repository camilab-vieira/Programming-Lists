#include <iostream>

void Merge(int A[], int l, int r){
    int i, j, k, m, temp[r];
    for(i = l; i <= r; i++){temp[i] = A[i];}
    m = (l + r)/2;
    j = l; k = m + 1;
    for(i = l; i <= r; i++){
        if(j == m + 1) A[i] = temp[k++];
        else if(k > r) A[i] = temp[j++];
        else if(temp[j] <= temp[k]) A[i] = temp[j++];
        else A[i] = temp[k++];
    }
}
void Mergesort(int A[], int l, int r){
    int m;
    if(l < r){
        m = (l + r)/2;
        Mergesort(A, l, m); Mergesort(A, m + 1, r); Merge(A, l, r);
    }
}

int main(){
    int i, qntChoc, qntCupom, valor, soma = 0;
    scanf("%d", &qntChoc);
    int choc[qntChoc];
    for(i = 0; i < qntChoc; i++){scanf("%d", &choc[i]); soma += choc[i];}
    scanf("%d", &qntCupom);
    int cupom[qntCupom];
    for(i = 0; i < qntCupom; i++){ scanf("%d", &cupom[i]);}
    Mergesort(choc, 0, qntChoc - 1);
    for(i = 0; i < qntCupom; i++){
        valor = qntChoc - cupom[i]; 
        valor = soma - choc[valor];
        printf("%d\n", valor);
    }
}