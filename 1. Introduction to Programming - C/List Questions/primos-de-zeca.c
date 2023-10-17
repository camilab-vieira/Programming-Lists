#include <stdio.h>

int main(){
    int A, B;
    int s=0, r=0, t=0, p=0,m=0;
    int p1=0,p2=0, p3=0;
    scanf("%d %d", &A, &B);

    m=A;
    if(A!=3)
        m--;
    for(int i=m; r<1; i--){
        for(int j=2; j<i; j++){
            if(i%j==0)
                s++;
        }
        if(s==0){
            r++;
            p++;
            p1=i;
        }else   
            s=0;
    }
    for(int i=A; i<=B; i++){
        for(int j=2; j<i; j++){
            if(i%j==0)
                s++;
        }
        if(s==0){
            p++;
        }else   
            s=0;
    }
    for(int i=A; r<=p; i++){
        for(int j=2; j<i; j++){
            if(i%j==0)
                s++;
        }
        if(s==0){
            r++;
            
            if(r%3==1)
                p1=i;
            if(r%3==2)
                p2= i;
            if(r%3==0)
                p3=i;
            if(p1>p3 && p1<p2){
                if(p1==(p3+p2)/2)
                    t++;
            }
            if(p2>p1 && p2<p3){
                if(p2==(p1+p3)/2)
                    t++;
            }
            if(p1>p3 && p2<p3){
                if(p3==(p2+p1)/2)
                    t++;
            }   
        }else   
            s=0;
    }
    
    printf("%d", t);

    return 0;
}