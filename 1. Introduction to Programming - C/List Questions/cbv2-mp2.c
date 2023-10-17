#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{ 
    char nome[30]; 
    int pontuacao; 
    int tentativas; 
} Competidor; 

//Funcao de ler competidores
Competidor* leCompetidores(Competidor* competidores, int qtdAtual, int qtdTotal){
    //Alocar dinamicamente
    competidores = (Competidor *) realloc(competidores, qtdTotal*sizeof(Competidor));
    if (competidores==NULL){
        printf("Erro"); 
        exit(1);
    }

    //Ler os competidores  
    for(int i=(qtdTotal-qtdAtual); i<qtdTotal; i++){
        printf("Nome: ");
        scanf(" %s", competidores[i].nome);

        printf("Tentativas: ");
        scanf("%d", competidores[i].tentativas);

        competidores[i].pontuacao=0;       
    }   
    return competidores;
}

//Funcao colocar tesouros
int** colocarTesouros(int** matriz, int n, int *numTesouros){
    //Definir a matriz
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((4*(i*i)+3*j)%11==0){
                matriz[i][j]=1;
                *numTesouros++;
            }else{
                matriz[i][j]=0;
            }
        }   
    }    
    return matriz;
}

//Funcao para cada rodada
void iniciarPartida(Competidor *competidores, int qtdAtual, int qtdTotal, int** matriz, int n, int *numTesouros){
    int x, y;
    for(int i=(qtdTotal-qtdAtual); i<qtdTotal; i++){
        int tentativasRestantes= competidores[i].tentativas;
        while(tentativasRestantes>0 && numTesouros>0){
            tentativasRestantes--;
            //Ler as coordenadas
            printf("Qual a %d° tentativa do competidor %s? (x,y)\n", (competidores[i].tentativas-tentativasRestantes), competidores[i].nome);
            scanf("(%d,%d)", &x, &y);
            //Encontrar as coordenadas na matriz
            if(matriz[x][y]==1){
                matriz[x][y]=0;        
                competidores[i].pontuacao++;
                *numTesouros--;
            }
        }
    }
}

//Funcao achar vencedor
void acharVencedor(Competidor *competidores, int qtdTotal){
    int maior=0, aux;
    for (int i=1; i<qtdTotal; i++) { 
        if (competidores[i].pontuacao>competidores[maior].pontuacao) {
            maior = i;
        } 
    }    

    strcpy(aux, competidores[0].nome);
    strcpy(competidores[0].nome, competidores[maior].nome);
    strcpy(competidores[maior].nome, aux);

    aux=competidores[0].pontuacao;
    competidores[0].pontuacao=competidores[maior].pontuacao;
    competidores[maior].pontuacao=aux;

    aux=competidores[0].tentativas;
    competidores[0].tentativas=competidores[maior].tentativas;
    competidores[maior].tentativas=aux;

    printf("Vencedor:\n");
    printf("%s\n",competidores[0].nome);
    printf("%d\n",competidores[0].pontuacao);
    printf("%d\n",competidores[0].tentativas);
}

int main(){
    int n, numTesouros, rodadas, qtdAtual, qtdTotal=0,r=0;

    Competidor *competidores=NULL;
    
    printf("Qual o numero de rodadas? ");
    scanf("%d", rodadas);

    while(r<rodadas){
        printf("Qual o numero de competidores dessa rodada? ");
        scanf("%d", qtdAtual);
        qtdTotal+=qtdAtual;
        leCompetidores(competidores,qtdAtual,qtdTotal);

        printf("Qual o tamanho da matriz? ");
        scanf("%d", &n);
        int matriz[n][n];
        numTesouros=0;
        colocarTesouros(matriz, n, &numTesouros);

        iniciarPartida(competidores, qtdAtual, qtdTotal, matriz, n, &numTesouros);
        r++;
    }

    acharVencedor(competidores,qtdTotal);

    free(competidores);

    return 0;
}
