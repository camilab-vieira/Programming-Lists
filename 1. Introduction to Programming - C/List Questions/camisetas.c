#include <stdio.h>

struct camisa{
    char nome[500];
    char cor[50];
    char tam;
};
int main(){
    int num,i,l,j,k,qntb=0,qntbp=0,qntbm=0,qntbg=0;
    int qntvp=0,qntvm=0,qntvg=0;
    char branco[7]={'b','r','a','n','c','o','\0'},m[500],t;
    struct camisa camiseta[10000];
    scanf("%d", &num);
    while(num!=0){
        qntb=0;qntbp=0;qntbm=0;qntbg=0;qntvp=0;qntvm=0;qntvg=0;
        for(i=0;i<num;i++){
            scanf(" %[^\n]",camiseta[i].nome);
            scanf("%s %c",camiseta[i].cor,&camiseta[i].tam);
        }
        for(i=0;i<num;i++){
            l=i;
            for(j=i;j<num;j++){
                if(strcmp(camiseta[i].cor,camiseta[j].cor)>0){
                    i=j;
                }
            }
            strcpy(m,camiseta[l].cor);
            strcpy(camiseta[l].cor,camiseta[i].cor);
            strcpy(camiseta[i].cor,m);
            t=camiseta[l].tam;
            camiseta[l].tam=camiseta[i].tam;
            camiseta[i].tam=t;
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            if(strcmp(camiseta[l].cor,branco)==0){
                qntb++;
            }
            i=l;
        }
        for(i=0;i<qntb;i++){
            l=i;
            for(j=i;j<qntb;j++){
                if(camiseta[i].tam-camiseta[j].tam<0){
                    i=j;
                }
            }
            t=camiseta[l].tam;
            camiseta[l].tam=camiseta[i].tam;
            camiseta[i].tam=t;
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            if(camiseta[l].tam=='P'){
                qntbp++;
            }
            if(camiseta[l].tam=='M'){
                qntbm++;
            }
            if(camiseta[l].tam=='G'){
                qntbg++;
            }
            i=l;
        }
        for(i=qntb;i<num;i++){
            l=i;
            for(j=i;j<num;j++){
                if(camiseta[i].tam-camiseta[j].tam<0){
                    i=j;
                }
            }
            t=camiseta[l].tam;
            camiseta[l].tam=camiseta[i].tam;
            camiseta[i].tam=t;
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            if(camiseta[l].tam=='P'){
                qntvp++;
            }
            if(camiseta[l].tam=='M'){
                qntvm++;
            }
            if(camiseta[l].tam=='G'){
                qntvg++;
            }
            i=l;
        }
        for(i=0;i<qntbp;i++){
            l=i;
            for(j=i;j<qntbp;j++){
                if(strcmp(camiseta[i].nome,camiseta[j].nome)>0){
                    i=j;
                }
            }
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            i=l;
        }    
        for(i=qntbp;i<qntbp+qntbm;i++){
            l=i;
            for(j=i;j<qntbp+qntbm;j++){
                if(strcmp(camiseta[i].nome,camiseta[j].nome)>0){
                    i=j;
                }
            }
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            i=l;
        }
        for(i=qntbp+qntbm;i<qntbp+qntbm+qntbg;i++){
            l=i;
            for(j=i;j<qntbp+qntbm+qntbg;j++){
                if(strcmp(camiseta[i].nome,camiseta[j].nome)>0){
                    i=j;
                }
            }
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            i=l;
        }
        for(i=qntbp+qntbm+qntbg;i<qntbp+qntbm+qntbg+qntvp;i++){
            l=i;
            for(j=i;j<qntbp+qntbm+qntbg+qntvp;j++){
                if(strcmp(camiseta[i].nome,camiseta[j].nome)>0){
                    i=j;
                }
            }
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            i=l;
        }
        for(i=qntbp+qntbm+qntbg+qntvp;i<qntbp+qntbm+qntbg+qntvp+qntvm;i++){
            l=i;
            for(j=i;j<qntbp+qntbm+qntbg+qntvp+qntvm;j++){
                if(strcmp(camiseta[i].nome,camiseta[j].nome)>0){
                    i=j;
                }
            }
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            i=l;
        }
        for(i=qntbp+qntbm+qntbg+qntvp+qntvm;i<num;i++){
            l=i;
            for(j=i;j<num;j++){
                if(strcmp(camiseta[i].nome,camiseta[j].nome)>0){
                    i=j;
                }
            }
            strcpy(m,camiseta[l].nome);
            strcpy(camiseta[l].nome,camiseta[i].nome);
            strcpy(camiseta[i].nome,m);
            i=l;
        }
        for(i=0;i<num;i++){
            printf("%s %c %s\n",camiseta[i].cor,camiseta[i].tam,camiseta[i].nome);
        }
        printf("\n");
        scanf("%d", &num);
    }

    return 0;
}