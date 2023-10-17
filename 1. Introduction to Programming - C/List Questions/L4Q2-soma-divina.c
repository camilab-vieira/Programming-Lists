#include <stdio.h>

int main(){
    int n, i, j; 
    scanf("%d", &n);
    int m1[n][n], m2[n][n], m3[n][n];
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &m1[j][i]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &m2[j][i]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            
            printf("%d\n", (m1[j][i]+m2[j][i]));
        }
    }
    if(n==0){
        printf("Vazia");
    }
    
    return 0;
}