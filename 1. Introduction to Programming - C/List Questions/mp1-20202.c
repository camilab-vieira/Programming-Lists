#include <stdio.h>

typedef struct {
    char nome[20];
    char mat[10];
    float vetor[5];
    int faltas;
}Aluno;

typedef struct{
    int qtd;
    char professor[20];
    char id[5];
    Aluno *alunos;
}Turma;

int main(){
    printf("----------------------MENU-------------------------\n");
    printf("Opcao 1------------------------------------Insercao\n");
    printf("Opcao 2----------------------------Remocao de Aluno\n");
    printf("Opcao 3-----------------------------------Aprovados\n");
    printf("Opcao 4----------------------------------Reprovados\n");
    printf("Opcao 5--------------------------------------Turmas\n");
    printf("Opcao 6----------------------------------------Sair\n");
    printf("---------------------------------------------------\n");
}