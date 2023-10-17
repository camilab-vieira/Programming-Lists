#include <stdio.h>

int main(){
    int total=0, i,count=0,r;
    char num[count];
    while(scanf("%c", &num[count])!=EOF){
    	count++;
    }
    count-=2;
    r=count%2;
    for(i=count;i>=0;i--){
        num[i]-=48;
        if(i%2!=r){
            num[i]*=2;
            if(num[i]>9){
                num[i]=num[i]%10+1;
            }
        }
        total+=num[i];
    }
    if(total%10==0){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }

    return 0;
}