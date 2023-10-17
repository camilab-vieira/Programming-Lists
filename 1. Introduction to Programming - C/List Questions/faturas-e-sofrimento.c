#include <stdio.h>
#include <string.h>

struct cliente{
    char nome[32];
    long int cartao;
    int t;
    int cvv;
    float valor;
};
struct bom{
    char nome[32];
    float valor;
};
struct ruim{
    char nome[32];
    float valor;
};

int main(){
    int n,i,j,total=0,ntotal=0;
    scanf("%d", &n);
    struct cliente c[n];
    struct bom a[n];
    struct ruim b[n];
    for (i = 0; i<n; i++){
        scanf(" %[^\n]", c[i].nome);
        c[i].t=0;
        scanf("%ld", &c[i].cartao);
        for(j=0;j<16;j++){
            c[i].t+=(c[i].cartao%10);
            c[i].cartao=c[i].cartao/10;
        }
        scanf("%d", &c[i].cvv);
        scanf("%f", &c[i].valor);
        if(c[i].t>=c[i].cvv){
            c[i].valor=0;
            strcpy(a[total].nome,c[i].nome);
            a[total].valor=c[i].valor;
            total++;
        }else{
            c[i].valor*=(c[i].cvv-c[i].t);
            strcpy(b[ntotal].nome,c[i].nome);
            b[ntotal].valor=c[i].valor;
            ntotal++;
        }
        c[i].t=0;
    }
    printf("Um total de %d clientes se beneficiaram da nova politica!\n", total);
    for (i = 0; i<total; i++){
        printf("%s %.2f\n",a[i].nome,a[i].valor);
    }
    printf("No entanto, %d clientes nao se beneficiaram da nova politica.\n", ntotal);
    for (i = 0; i<ntotal; i++){
        printf("%s %.2f\n",b[i].nome,b[i].valor);
    }

    return 0;
}