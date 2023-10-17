#include <stdio.h>

int main(){
    int c[100000], m;
    int count=0,i,t=0,j, k, s=0, p=0, n=0;
    while(scanf("%d ", &c[count])!=EOF){
        count++;
    }
    for(i=0; i<count; i++){
        t=i;
        for(j=i;j<count;j++){
            if(c[i]>c[j]){
                i=j;
            }
        }
        m=c[t];
        c[t]=c[i];
        c[i]=m;
        i=t;
    }
    for(i=0;i<count;i++){
        printf("%d ", c[i]);
    }
    printf("\n");
    if(count%2==0){
        printf("0");
    }else{
        for(i=0;i<count;i++){
            for(j=0;j<count;j++){
                if(c[i]==c[j]){
                    s++;
                }
            }
            if(s%2==1){
                printf("%d", c[i]);
                i=count;
            }
            s=0;
        }
    }
    return 0;
}