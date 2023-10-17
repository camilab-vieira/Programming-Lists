#include <iostream>

using namespace std;

int tamanho(int n, int sum){
    if(n == 0) return sum;
    else{
        return tamanho(n-1,sum+n);
    }
}

int soma(int* vet, int i, int tam1, int tam){
    
}

int main(){
    int tam, tam1;
    cin>>tam;
    tam1 = tamanho(tam, 0);
    int vet[tam1], i = 0;
    while(i < tam){
        cin>>vet[i];
        i++;
    }


    return 0;
}
