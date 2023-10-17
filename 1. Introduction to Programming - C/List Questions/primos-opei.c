#include <stdio.h>

int main(){
    int n,i,j,s=0;
    scanf("%d",&n);

    for(i=2;i<=n;i++){
        for(j=2;j<=i;j++){
            if(i%j==0){
                s++;
            }
        }
        if(s==1){
            printf("%d\n",i);
        }
        s=0;
    }

    return 0;
}