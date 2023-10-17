#include <stdio.h>
#include <stdlib.h>

/*int movePeao(char **tab, char jogada[7]){
    int i, j, posicao;
    posicao = acharPeca(tab, jogada);
    if(jogada[0] == 80){

    }
}
int moveTorre(char **tab, char jogada[7]){}
int moveBispo(char **tab, char jogada[7]){}
int moveCavalo(char **tab, char jogada[7]){}
int moveRei(char **tab, char jogada[7]){}
int moveRainha(char **tab, char jogada[7]){}

int acharPeca(char **tab, char jogada[7]){
    int i, j, posicao;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(tab[i][j] == jogada[0]){
                posicao = i*10 + j;
            }
        }
    }

    return posicao;
}
*/
int **tabuleiroInicial(char **tab){
    int i, j;

    tab[0][0] = 't'; tab[0][1] = 'c'; tab[0][2] = 'b'; tab[0][3] = 'd'; 
    tab[0][4] = 'r'; tab[0][5] = 'b'; tab[0][6] = 'c'; tab[0][7] = 't';
    tab[7][0] = 'T'; tab[7][1] = 'C'; tab[7][2] = 'B'; tab[7][3] = 'D'; 
    tab[7][4] = 'R'; tab[7][5] = 'B'; tab[7][6] = 'C'; tab[7][7] = 'T';


    for(i = 1; i < 7; i++){
        for(j = 0; j < 8; j++){
            if(i == 1) tab[i][j] = 'p';    
            else if(i == 6) tab[i][j] = 'P';    
            else tab[i][j] = '0';
        }
    }

}

int main(){
char tab[8][8], jogada[7];
int disponivel, i, j;

tab[8][8] = tabuleiroInicial(tab);

/*if(jogada[0] == 112 || jogada[0] == 80){
    disponivel = movePeao(tab, jogada);
}*/
for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            printf("%c ", tab[i][j]);
        }
        printf("\n");
}

return 0;
}
