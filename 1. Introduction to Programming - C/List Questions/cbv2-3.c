#include <stdio.h>

typedef struct{
    int matricula;
    float nota;
    char curso[20];
}Aluno;

int main(){
    Aluno aluno={9999,10.0,"Eng. Computacao"};
    Aluno *pAluno= &aluno;
    printf("Matricula: %d\n", (*pAluno).matricula);
    printf("Nota: %.2f\n", (*pAluno).nota);
    printf("Curso: %s\n", (*pAluno).curso);
    
    return 0;
}