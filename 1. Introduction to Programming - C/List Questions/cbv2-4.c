#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *pVet=NULL, *pVet1=NULL, i, j;
    printf("Tamanho do vetor: ");
    scanf("%d",&n);
    while(n>0){
        pVet = (int *) realloc(pVet1, n*sizeof(int));
        if(pVet==NULL){ 
            free(pVet1); exit(1); 
        }
        pVet1=pVet;
        printf("Tamanho do vetor: ");
        scanf("%d",&n);
    }
    free(pVet);

    return 0;
}