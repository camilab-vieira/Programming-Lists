#include <stdio.h>
#include "sigazinho.h"

int main(){
    int opcao;
    Aluno *alunos = NULL;
    int qnt = 0;

    do {
        printf("\nMENU DE ESCOLHAS DO SIGazinho\n\n");
        printf("1....Cadastrar um aluno\n");
        printf("2....Procurar um aluno\n");
        printf("3....Remover um aluno\n");
        printf("4....Lista melhores alunos\n");
        printf("5....Lista alunos cadastrados\n");
        printf("6....Sair do sistema\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: alunos = cadastraAluno(alunos, &qnt); break;
            case 2: procuraAluno(alunos, qnt); break;
            case 3: removeAluno(&alunos, &qnt); break;
            case 4: listaMelhores(alunos, qnt); break;
            case 5: listaAlunos(alunos, qnt); break;
            case 6: break;
            default: printf("Preste atencao!!! Opcao invalida\n");
        }
    } while(opcao!=6);
}