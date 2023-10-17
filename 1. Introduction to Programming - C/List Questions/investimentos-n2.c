#include <stdio.h>

int main(){
    int n, m, a;
    scanf("%d %d", n, m);

    for(int i=0;i<m;i++){
        a=m;
        a++;
        if(30%a==0){
            printf("Curvou\n");
        }
        else{
            printf("Pedro se cagou todo e foi pego.\n");
        }
        m++;
    }

    return 0;
}