#include <stdio.h>

int main(){
    int m, n, i, j, k, inst;
    scanf("%dx%d\n%d", &n,&m,&inst);
    int m1[n][m];
    char v[inst*2];
    for(i=0; i<(inst*2); i+=2){
        scanf(" %c%d", &v[i],&v[i+1]);
        v[i]-=97;
        v[i+1]--;
    }
    for(i=0; i<n; i++){
        for(j=0;j<m;j++){
            m1[i][j]=0;
        }
    }
    if(inst>=(m*n)){
        printf("BANDECLAY OVERLOAD!");
    }else{
        for(i=0; i<(inst*2); i+=2){
            for(j=-1; j<=1; j++){
                for(k=-1; k<=1; k++){
                    if((v[i]+j)>=0&&(v[i+1]+k)>=0&&(v[i]+j)<n&&(v[i+1]+k)<m){
                        if(j==0&&k==0){
                            m1[v[i]+j][v[i+1]+k]=9;
                        }
                        if(m1[v[i]+j][v[i+1]+k]!=9){
                            m1[v[i]+j][v[i+1]+k]+=1;
                        }
                    }
                }
            }
        }
        k=n;
        for(i=0; i<n; i++){
            for(j=0;j<m;j++){
                printf("%d ", m1[i][j]);
            }
            n=k;
            printf("\n");
        }
    }

    return 0;
}