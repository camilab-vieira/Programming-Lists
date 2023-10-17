#include <stdio.h>

int main() {
	int laranjas, bananas, ovos, leite;
    int bananasCompradas=0, laranjasCompradas=0, ovosComprados=0, leiteComprado=0;

    scanf("%d %d %d %d", &laranjas, &bananas, &ovos, &leite);
    
    if(laranjas<0 || bananas<0 || ovos<0 || leite<0){
        printf("lurn maf :(\n");
    } 
    else{
        if(laranjas == 0){
            laranjasCompradas= bananas*bananas;
        }
        if(laranjasCompradas>0){
                bananasCompradas= 2;
        }
        if((bananas+bananasCompradas)>ovos && laranjasCompradas>ovos){
            ovosComprados= laranjasCompradas-ovos;
        } 
        if(ovosComprados>0){    
            if(leite<2000){
                leiteComprado= 2000-leite;
            }
        } 
        else{
            leiteComprado= 500;
        }
        printf("%d laranjas\n%d bananas\n%d ovos\n%d mL de leite\n", laranjasCompradas, bananasCompradas, ovosComprados, leiteComprado);
    }  
	return 0;
}