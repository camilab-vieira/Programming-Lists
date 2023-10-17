#include <stdio.h>
#include <string.h>

struct dados{
    char nome[21];
    int idade;
    int id;
    int pontos;
};
int main(){
    int n,i,j,s=0;
    struct dados a[1];
    scanf("%d %d",&a[0].idade,&a[0].id);
    scanf(" %[^\n]",a[0].nome);
    scanf("%d %d",&a[1].idade,&a[1].id);
    scanf(" %[^\n]",a[1].nome);
    a[0].pontos=0;a[1].pontos=0;
    n=strcmp(a[0].nome,a[1].nome);
    if(n>0){
        a[0].pontos+=2;
    }else{
        if(n!=0){
            a[1].pontos+=2;
        }
    }
    for(i=2;i<a[0].idade;i++){
        if(a[0].idade%i==0){
            s++;
        }
    }
    if(s==0){
        a[0].pontos+=4;
    }
    s=0;
    for(i=2;i<a[1].idade;i++){
        if(a[1].idade%i==0){
            s++;
        }
    }
    if(s==0){
        a[1].pontos+=4;
    }
    s=0;
    for(i=0;i*i<=a[0].id;i++){
        if(i*i==a[0].id){
            s++;
        }
    }
    if(s!=0){
        a[0].pontos+=3;
    }
    s=0;
    for(i=0;i*i<=a[1].id;i++){
        if(i*i==a[1].id){
            s++;
        }
    }
    if(s!=0){
        a[1].pontos+=3;
    }
    if(a[0].pontos>a[1].pontos){
        printf("%s WINS\n",a[0].nome);
    }
    if(a[1].pontos>a[0].pontos){
        printf("%s WINS\n",a[1].nome);
    }
    if(a[0].pontos==a[1].pontos){
        printf("CInCABECAS EMPATADOS\n");
    }

    return 0;
}