#include <stdio.h>

struct passageiro{
    int num;
    int dia;
    int mes;
    int ano;
    char de[500];
    char para[500];
    int hora;
    int min;
    int min1;
    int poltrona;
    int idade;
    char nome[501];
};

int main(){
    int i,med=0,qnt=0;
    struct passageiro a[1000];
    scanf("%d", &a[qnt].num);
    while(a[qnt].num!=-1){
        scanf("%d/%d/%d\n%[^\n]\n%[^\n]", &a[qnt].dia,&a[qnt].mes,&a[qnt].ano,a[qnt].de,a[qnt].para);
        scanf("%d:%d",&a[qnt].hora,&a[qnt].min);
        scanf("%d\n%d\n%[^\n]",&a[qnt].poltrona,&a[qnt].idade,a[qnt].nome);
        med+=a[qnt].idade;qnt++;
        scanf("%d", &a[qnt].num);
    }
    for(i=0;i<qnt;i++){
        if(a[i].poltrona%2==0){
            if(a[i].idade>(med/qnt)){
                printf("%s\n",a[i].nome);
            }
        }
    }

    return 0;
}