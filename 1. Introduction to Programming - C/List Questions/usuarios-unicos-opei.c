#include <stdio.h>

int main(){
    int n,i,j,s=0,r=0;
    scanf("%d",&n);
    long long int v1[n];
    for (i=0;i<n; i++){
        scanf("%lld", &v1[i]);
        for (j=0; j<i; j++){
            if(v1[j]==v1[i]){
                s++;
            }
        }
        if(s==0){
            r++;
        }
        s=0;
    }
    printf("%d\n",r);

    return 0;
}