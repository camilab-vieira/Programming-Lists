#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char red, green, blue;
} RGB;

typedef struct{
    char nome[50], login[10];
    int idade;
} Aluno;

typedef struct{
    char nome[20], descricao[100];
    int ch;
    Aluno alunos[50];
    int qnt_alunos;
} Curso;

struct CIn{
    Curso cursos[3];
    int qnt_cursos;
};

struct CTG{
    Curso cursos[3];
    struct CIn cin;
    int qnt_cursos;
};

Aluno funcao(char nome[20],int idade){
    Aluno alunos={nome, idade};
    return alunos;
}

float somaVet(float *vetor, int tamVet) {
    float sum=0;
    for(int i=0; i<tamVet; i++)
        sum += vetor[i];
    return sum;
}
// somaVet(vet, tam);

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//swap(&x,&y);

int main(){
    int i, j, tam=4, vet[tam], indMenor, aux, flag, freq[tam], elem;
    char palavras[4][4]= {{"zoo"},{"rai"},{"abc"},{"poo"}}, aux1[tam];

    //Menor
    for(i = 1; i < tam; i++){
        if(vet[i] < vet[indMenor]){
            indMenor = i;
        }
    }

    //Sort
    for(i = 0; i < (tam-1); i++) {
        indMenor = i;
        for(j = (i+1); j < tam; i++){
            if(vet[j] < vet[indMenor]){
                indMenor = j;
            }
        }
        if(indMenor != i) {
            aux = vet[i];
            vet[i] = vet[indMenor];
            vet[indMenor] = aux;
        }
    }

    //Contar repetição I
    for(i = 0; i < tam; i++) {
        printf("Digite elemento: "); scanf("%d", &elem);
        vet[elem]++;
    }

    //Contar repetição II
    for(i = 0; i < tam; i++) {
        freq[i] = 1;
        for(j = (i+1); j < tam && !flag; j++) {
            if(vet[i] == vet[j] && vet[j] != NULL){ 
                vet[j] = NULL;
                freq[i]++;
            }
        }
    }

    //Bubble sort
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < (tam-1)-i; j++){
            if( strcmp(palavras[j], palavras[j+1]) > 0 ){
                strcpy(aux1, palavras[j]);
                strcpy(palavras[j], palavras[j+1]);
                strcpy(palavras[j+1], aux1);
            }
        }
    }
    //strcmp: letra do primeiro - letra do segundo. strcpy: (destino,copiada).

    //int para str
    i=0;
    while(tam != 0) {
        printf("String antes: [%s]\n", palavras[0]);
        i = i + 1;
        for(j = i; j > 0; j--){
            palavras[0][j] = palavras[0][j-1];
        }
        printf("Unidade separada: %d\n", tam % 10);
        printf("Unidade separada como caractere: %c\n", tam % 10 + 48);
        palavras[0][0] = (tam % 10 + 48);
        printf("String apos: [%s]\n", palavras[0]);
        tam = tam / 10;
        printf("Entrada atual: %d\n", tam);
    }

    //Struct (se definida na main, só poderá ser acessada pela main) 
    Curso EC = {"Eng. Computação", "é melhor que CC", 4000, {{"aluno1", "opa", 19}, {.nome = "aluno2", .idade = 19, .login = "opa2"}}, 2};
    struct CIn cin = {.qnt_cursos = 3, .cursos = {EC}};
    cin.cursos[0] = EC;
    struct CTG ctg;
    ctg.cin = cin;
    Aluno aluno;
    aluno = (Aluno) {"\0", "\0", 23}; // casting

    //Struct com ponteiro
    Aluno *eu; 
    eu = (Aluno *) malloc(tam * sizeof(Aluno)); 
    if(eu==NULL) exit(1);
    strcpy((*eu).nome, "Alexandre");
    (*eu).idade = 4;

    //Struct com ponteiro e setas
    //No calloc, há a inicialização com 0
    Aluno *eu;
    eu = (Aluno *) calloc(tam, sizeof(Aluno)); 
    if(eu==NULL) exit(1);
    strcpy(eu -> nome, "Alexandre");
    eu -> idade = 4;

    //Struct com ponteiro e vetor
    Aluno *eu; 
    eu = (Aluno *) malloc(sizeof(Aluno));
    if(eu==NULL) exit(1);
    strcpy(eu[0].nome, "Alexandre");
    eu[0].idade = 4;

    //Jeito ideal de alocar
    int *vetor = NULL, *vetAt = NULL, tam = 0, i; 
    scanf("%d", &i);
    while(i>0){
        vetAt = (int *) realloc(vetor, (tam+1)*sizeof(int));
        if(vetAt==NULL){ free(vetor); exit(1);}
        vetor = vetAt;
        vetAt[tam] = tam;
        tam++; 
        scanf("%d", &i);
    }
    for(i = 0; i < tam; i++)
        printf("vet[%d]=%d\n", i+1, vetAt[i]);
    free(vetAt);

    return 0;
}