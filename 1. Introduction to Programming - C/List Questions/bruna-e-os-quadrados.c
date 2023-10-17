#include <stdio.h>

int main(){
    int n, i, j, h, k, p=1, q=0, s=0;
    scanf("%d", &n);
    int m1[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &m1[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            p=1;
            for(k=0;k<p;k++){
                for(h=0;h<p;h++){
                    if(m1[i+k][j+h]==1&&(i+k)<n&&(j+h)<n){
                        s++;
                    }else{
                        k=p;h=p;
                    }
                    if(s==(p*p)){
                        p++;
                        k=0;
                        h=-1;
                        if(s>q){
                            q=s;
                        }
                        s=0;
                    }
                }
            }
            s=0;
        }
    }
    printf("%d",q);

    return 0;
}