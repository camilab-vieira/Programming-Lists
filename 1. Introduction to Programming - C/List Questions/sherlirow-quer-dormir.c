#include <stdio.h>

int main(){
    int n, l, c, i, j, k, h, a=0, b=0, p=0, t=0;
    scanf("%d %d %d", &n, &l, &c);
    int m1[n][2], t1[l][c];
    for(i=0; i<n; i++){
        for(j=0; j<2; j++){
            scanf("%d", &m1[i][j]);
        }   
    }
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            scanf("%d", &t1[i][j]);
        }   
    }
    for(k=1;k<=4;k++){
        for(h=0; h<n; h++){
            for(i=-m1[h][0]; i<l-m1[h][0]; i++){
                for(j=-m1[h][1]; j<c-m1[h][1]; j++){
                    if(i!=0){
                        j=0;
                    }
                    a=m1[h][0]+i;
                    b=m1[h][1]+j;
                    if(t1[a][b]==k){
                        t++;
                    }
                    if(i!=0&&j==0){
                        j=(c-m1[h][1]);
                        
                    }
                }
            }  
            if(t>p){
                p=t;
            }
            t=0;  
        }
    }
    printf("A pontuacao da equipe vencedora sera %d ponto(s)!\n", p);
    
    return 0;
}