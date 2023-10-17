#include <stdio.h>
#include <string.h>

struct aluno{
    char cod[31];
    char nome[501];
    int idade;
    int sexo;
    float nota;
};
struct disc{
    char cdis[26];
    char ndis[101];
    char nome[100][501];
    int qnt;
};
struct matricula{
    char cod[31];
    char cdis[26];
};


int main(){
    int i,j,k,l,n=0,s=0,alunos, qdis, sm=0,sf=0,num;
    char m[501],p[501];
    float med=0, medI=0, medII=0;
    scanf("%d",&alunos);
    struct aluno a[alunos];
    for(i=0;i<alunos;i++){
        scanf("%s\n%[^\n]\n%d\n%d\n%f", a[i].cod,a[i].nome,&a[i].idade,&a[i].sexo,&a[i].nota);
        if(a[i].sexo==0){sf++;}else{sm++;}
        med+=a[i].idade; if(a[i].nota>7.5){medI+=a[i].idade;medII++;}
    }
    scanf("%d",&qdis);
    struct disc b[qdis];
    for(i=0;i<qdis;i++){
        b[i].qnt=0;
        scanf("%s\n%[^\n]",b[i].cdis,b[i].ndis);
    }
    scanf("%d",&num);
    struct matricula c[num];
    for(i=0;i<num;i++){
        scanf("%s %s",c[i].cod,c[i].cdis);
        for(j=0;j<qdis;j++){
            if(strcmp(b[j].cdis,c[i].cdis)==0){
                for(k=0;k<alunos;k++){
                    if(strcmp(a[k].cod,c[i].cod)==0){
                        strcpy(b[j].nome[b[j].qnt],a[k].nome);
                        b[j].qnt++;
                    }
                }
            }
        }
    }
    printf("%d\n%d\n%.2f\n%.2f\n", sm,sf,med/alunos,medI/medII);
    for(i=0;i<qdis;i++){
        l=i;
        for(j=i;j<qdis;j++){
            if(strcmp(b[i].ndis,b[j].ndis)>0){
                i=j;
            }
        }
        n=b[l].qnt;
        b[l].qnt=b[i].qnt;
        if(b[i].qnt>0){
            s=b[i].qnt;
        }else{s=n;}
        b[i].qnt=n;
        for(k=0;k<s;k++){
            strcpy(p,b[l].nome[k]);
            strcpy(b[l].nome[k],b[i].nome[k]);
            strcpy(b[i].nome[k],p);
        }
        strcpy(m,b[l].cdis);
        strcpy(b[l].cdis,b[i].cdis);
        strcpy(b[i].cdis,m);
        strcpy(m,b[l].ndis);
        strcpy(b[l].ndis,b[i].ndis);
        strcpy(b[i].ndis,m);
        i=l;
    }
    for(k=0;k<qdis;k++){
        for(i=0;i<b[k].qnt;i++){
            l=i;
                for(j=i;j<b[k].qnt;j++){
                if(strcmp(b[k].nome[i],b[k].nome[j])>0){
                    i=j;
                }
            }
            strcpy(m,b[k].nome[l]);
            strcpy(b[k].nome[l],b[k].nome[i]);
            strcpy(b[k].nome[i],m);
            i=l;
        }
    }
    for(j=0;j<qdis;j++){
        printf("%s\n%d\n",b[j].ndis,b[j].qnt);
        for(i=0;i<b[j].qnt;i++){
            printf("%s\n",b[j].nome[i]);
        }
    }
        
    return 0;
}