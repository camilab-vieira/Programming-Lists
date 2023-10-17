#include <stdio.h>
#include <stdlib.h>
int n;
int primos[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};
int usados[20];
int ciclo[20];


int ehprimo(int x){
    int i;
    for(i=0;i<13;i++){
        if(x==primos[i]){
            return 1;
        }
    }
    return 0;
}

void backtracking(int x){
    if( ehprimo(ciclo[n]+ciclo[n-1]) && x==n-1 ){
        for(int i=0;i<n;i++){
            if( i == n-1 ){
                printf("%i",ciclo[i]);
            }
            else{
                printf("%i ",ciclo[i]);
            }
        }
        printf("\n");
        return;
    }
    for(int i=2;i<=n;i++){
        if(ehprimo(ciclo[x]+i) && !usados[i]){
            usados[i]=1;
            ciclo[x+1]=i;
            backtracking(x+1);
            usados[i]=0;
        }
    }
}


int main(){
    int i=1;
    int pimba=0;


    //primos


    while(scanf("%i",&n)!=EOF){
        if(pimba!=0){
            printf("\n");
        }
        printf("Case %i:\n",i);

        ciclo[0]=ciclo[n]=1;
        backtracking(0);

        pimba=1;
        i++;
    }




    return 0;
}