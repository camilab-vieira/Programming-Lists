#include <stdio.h>

int main(){
    int a, n, i, s=0;
    scanf("%d %d", &a, &n);

    for(i=a; i!=0 && s<(n*60); i++){
        if(i%13==0){
            if((i-60)%60==0)
                i+=30;
            else
                i-=60;
        }
        s++;
    }
    if(i==0)
        printf("%d", s);
    else
        printf("fui pedir comida mesmo\n");
}