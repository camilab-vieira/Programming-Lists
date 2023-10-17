#include <stdio.h>

int main(){
    int T, i, s=0, m, n=0, p=0;
    scanf("%d\n", &T);
    
    for(int l=0;l<T;l++){
        int TAM;
        scanf("%d\n", &TAM);
        int v[TAM];
        for(i=0; i<TAM; i++){
            scanf("%d", &v[i]);
        }
        for(i=0; i<TAM; i++){
            if((i<(TAM-1))&&(v[i]>v[i+1])){
                s++;
            }
            else{
                if(s>n){
                    n=s;
                    p=m;  
                }
                s=0;
            }
            if(s==1){
                m=i;
            }
        }
        if(n>0){
            n++;
        }
        printf("%d\n", n);
        if(n>0){
            for(i=p; i<(n+p); i++){
                printf("%d ", v[i]);
            }
            printf("\n");
        }
        s=0;
        m=0;
        n=0;
        p=0;
    }
}