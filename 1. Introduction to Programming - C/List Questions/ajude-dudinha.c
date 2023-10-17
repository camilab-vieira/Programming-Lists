#include <stdio.h>

int main(){
    int N, K, P, m=0, s=0, t=0, r=0, a=0, b=0, c=0;
    scanf("%d %d %d", &N, &K, &P);
    
    for(int i=N; i<K; i++){
        m=i;
        for(int j=2; j<=i; j++){
            while(m%j==0){
                m= m/j;
                s++;
            }
            if(s==1&&j%2==1)
                t++;
            else{
                if(s>0&&j%2==1){
                    c++;
                }
            }

            if(s>0&&j%2==1){
                b++;
            }
            s=0;
        }
        if(t==P&&P!=0&&c==0){
            if(a==0)
                r= i;  
            a++;  
        }
        if(P==0&&b==0){
            if(a==0)
                r= i;  
            a++;
        }
        t=0;
        b=0;
        c=0;
    }
    a--;
    if(r>0||a>0)
        printf("%d %d", r, a);
    else    
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.");
    return 0;
}