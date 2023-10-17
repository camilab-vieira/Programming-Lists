#include <stdio.h>

int main(){
    int vet[5]={0,2,4,6,8}, *p, i;
    p=vet;

    //a):
    printf("Endereco guardado em vet: %p\n", vet);
    printf("Endereco guardado em p: %p\n", p);
    //b):
    for(i=0;i<5;i++){
        printf("Vet[%d]=%d\n", i+1, p[i]);
    }
    //c):
    for(i=0;i<5;i++){
        printf("Vet[%d]=%d\n", i+1, *(p+i));
    }
    //d):
        //Mesma coisa de b)
    for(i=0;i<5;i++){
        printf("Vet[%d]=%d\n", i+1, vet[i]);
    }
        //Mesma coisa de c)
    for(i=0;i<5;i++){
        printf("Vet[%d]=%d\n", i+1, *(vet+i));
    }
     
    return 0;
}