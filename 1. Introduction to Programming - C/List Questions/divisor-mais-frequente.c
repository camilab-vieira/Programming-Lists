#include <stdio.h>

int main(){
    int a, b=0, mf=0,f=0;
    scanf("%d", &a);

    for(int i=2; a>1; i++){
        while(a%i==0&&a>1){
            a= a/i;
            b++;
        }
        if(b>f){
            f= b;
            mf= i;
        }
        b=0;
    }
    printf("mostFrequent: %d, frequency: %d", mf, f);
}
