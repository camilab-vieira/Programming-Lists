#include <stdio.h>

int main(){
    long long int x=0, c=0,d=0, K=0, s=0, n=0, t=0, p=0;
    char b=0;
    scanf("%lld", &x);
    
    for(int i=0; i<2*x;i++){
        scanf("%c", &b);
        if(b>47&&b<58){
            d++;
        }else{
            c++;
        }
    }
    c-=x;
    scanf("%lld", &K);
    for(int i=1;i<=K;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                t++;
            }
        }
        if(i==1){
            t++;
        }
        if(t==0){
            n=1;
            for(int l=1; l<=i;l++){
                n*=d;
            }
        }
        if(t!=0){
            s=1;
            for(int m=1; m<=i;m++){
                s*=c;
            }
        }
        printf("Tamanho %lld:\nSequencias: %lld, Numeros: %lld\n", i,s,n);
        t=0;
        n=0;
        s=0;
    }
    if(K==0)
    return 0;   
}