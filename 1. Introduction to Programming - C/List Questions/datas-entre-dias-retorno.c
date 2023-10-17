#include <stdio.h>

int main(){
    int TAM, i, m, s=0, j, t=0;
    scanf("%d\n", &TAM);
    int v[TAM], b[TAM];

    for(i=0; i<TAM; i++){
        scanf("%d", &v[i]);
    }
    for(i=0; i<TAM; i++){
        b[i]=v[i];
    }
    for(i=0; i<TAM; i++){
        t=i;
        for(j=i;j<TAM;j++){
            if(v[i]>v[j]){
                i=j;
            }
        }
        m=v[t];
        v[t]=v[i];
        v[i]=m;
        i=t;
    }
    for(i=0; i<TAM; i++){
        if(b[i]==v[i]){
            s++;
        }
    }
    printf("%d\n", s);
    for(i=0; i<TAM; i++){
        if(b[i]==v[i]){
            printf("%d %d\n", v[i], i+1);
        }
    }
    
    return 0;
}