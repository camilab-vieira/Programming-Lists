#include <stdio.h>
#include <math.h>

int main(){
    int l,c,i,j,k;
    float b,x;
    scanf("%d %d", &l, &c);
    int m1[l][c];
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d", &m1[i][j]);
        }
    }
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            if(m1[i][j]!=-1&&j>0){
                x=j;
                b=pow(m1[i][j],(1/x));
                k=b;
                j=0;
                for(j=0;j<c;j++){
                    x=j;
                    m1[i][j]=pow(k,x);
                }
                j=c;
            }
        }
    }
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            if(j==(c-1)){
                printf("%d", m1[i][j]);
            }else{
                printf("%d ", m1[i][j]);    
            }
        }
        printf("\n");
    }

    return 0;
}