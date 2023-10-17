#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota;
} Aluno;

Aluno *cadastraAluno(Aluno *alunos, int *qnt){
    Aluno alunoNovo;
    scanf(" %s", alunoNovo.nome);
    scanf("%d", &alunoNovo.matricula);
    scanf("%f", &alunoNovo.nota);
    alunos = (Aluno *) realloc(alunos, ((*qnt)+1) * sizeof(Aluno));
    if(alunos == NULL){exit(1);}
    alunos[*qnt] = alunoNovo;
    (*qnt)++;
    return alunos;
} 
void procuraAluno(Aluno *alunos, int qnt){
    int matriculaProcurada;
    scanf("%d", &matriculaProcurada);
    for(int i = 0; i < qnt; i++){
        if(alunos[i].matricula == matriculaProcurada){
            printf("%s\n%d\n%.2f\n\n", alunos[i].nome, alunos[i].matricula, alunos[i].nota);
        }
    }
}
void removeAluno(Aluno **alunos, int *qnt){
    int matriculaProcurada;
    scanf("%d", &matriculaProcurada);
    for(int i = 0; i < (*qnt); i++){
        if((*alunos)[i].matricula == matriculaProcurada){
            *alunos = (Aluno *) realloc(alunos, (*qnt) * sizeof(Aluno));
            (*alunos)[i] = (*alunos)[(*qnt)-1];
            (*qnt)--;
        }
    }
} 
void listaMelhores(Aluno *alunos, int qnt){
    float soma = 0;
    for(int i = 0; i < qnt; i++){
        soma += alunos[i].nota;
    }
    for(int i = 0; i < qnt; i++){
        if(alunos[i].nota >= soma/qnt){
            printf("%s\n%d\n%.2f\n\n", alunos[i].nome, alunos[i].matricula, alunos[i].nota);
        }
    }
}
void listaAlunos(Aluno *alunos, int qnt){
    if(alunos == NULL){
        printf("NULL, %d\n", qnt);
    }
    for(int i = 0; i < qnt; i++){
        printf("%s\n%d\n%.1f\n\n", alunos[i].nome, alunos[i].matricula, alunos[i].nota);
    }
} 