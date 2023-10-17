#include <stdio.h>

int main(){
    int v, n, i, s=0, m=0;
    scanf("%d %d\n", &v, &n);
    int a[n];
    
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++){
        for(int j=(i+1); j<n; j++){
            for(int k=(j+1); k<n; k++){
                s=a[i]+a[j]+a[k];
                if(s==v){
                    m++;
                }
            }
        }
    }
    if(m==0){
        printf("Zeca vai ter que trabalhar.\n");
    }
    else{
        printf("Zeca nao vai ter que trabalhar!\n");
    }
}