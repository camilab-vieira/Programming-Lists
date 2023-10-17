#include <stdio.h>

int main(){
    int array[100000],i,count=0,n1=0,n2=0;
    while(scanf("%d",&array[count])!=EOF){
        count++;
    }
    for(i=0;i<count;i++){
        if(array[i]>n2&&array[i]<=n1){
            n2=array[i];
        }
		if(array[i]>n1){
            n2=n1;
            n1=array[i];
        }
    }
    printf("Apesar de muitas moedinhas o maior produto encontrado foi %d\n", n1*n2);
    
    return 0;
}