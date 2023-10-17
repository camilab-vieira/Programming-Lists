#include <stdio.h>

int main(){
    char n[20];
    int m1[4][4],i,j,k,p=0,a,b;
    for(i=0;i<20;i++){
        scanf(" %c", &n[i]);
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            m1[i][j]=0;
        }
    }
    i=0;j=0;
    for(k=0;k<20;k++){
        if(n[k]==99){
            i--;
            m1[i][j]++;
            if(m1[i][j]>p){
                p=m1[i][j];
                a=i; b=j;
            }
        }
        if(n[k]==98){
            i++;
            m1[i][j]++;
            if(m1[i][j]>p){
                p=m1[i][j];
                a=i; b=j;
            }
        }
        if(n[k]==101){
            j--;
            m1[i][j]++;
            if(m1[i][j]>p){
                p=m1[i][j];
                a=i; b=j;
            }
        }
        if(n[k]==100){
            j++;
            m1[i][j]++;
            if(m1[i][j]>p){
                p=m1[i][j];
                a=i; b=j;
            }
        }
    }
    printf("Coordenada X:%d, Y:%d\n", b, a);

    return 0;
}