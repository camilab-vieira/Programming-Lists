#include <stdio.h>
#include <stdlib.h>

int movePeao(char **tab, char jogada[7]){
    int i, j, jogadaResumida[4];
    traduzirJogada(jogada, jogadaResumida);

    if(tab[jogadaResumida[2]][jogadaResumida[3]] == '0'){
        //comando de andar uma casa para frente
        if(jogadaResumida[0] == jogadaResumida[2]){
            if(jogada[0] == 'P')
                if(jogadaResumida[1] == (jogadaResumida[3] - 1)){
                tab[jogadaResumida[0]][jogadaResumida[2]] = '0';
                tab[jogadaResumida[2]][jogadaResumida[3]] = 'P';
                return 1;
                }
            if(jogada[0] == 'p'){
                    if(jogadaResumida[1] == (jogadaResumida[3] + 1)){     
                        tab[jogadaResumida[0]][jogadaResumida[2]] = '0';
                        tab[jogadaResumida[2]][jogadaResumida[3]] = 'P'; 
                        return 1;    
                    }            
            }
        }
        //comando diagonal
        if(abs(jogadaResumida[0] - jogadaResumida[2]) == 2 ){
            if(jogada[0] == 'P'){
                if(jogadaResumida[1] == (jogadaResumida[3] - 2))
                    if(tab[jogadaResumida[2]-1][jogadaResumida[3]-1] != '0'){     
                        tab[jogadaResumida[0]][jogadaResumida[2]] = '0';
                        tab[jogadaResumida[2]][jogadaResumida[3]] = 'P'; 
                        return 1;    
                    }  
            }
            if(jogada[0] == 'p'){
                if(jogadaResumida[1] == (jogadaResumida[3] + 2))
                    if(tab[jogadaResumida[2]+1][jogadaResumida[3]+1] != '0'){     
                        tab[jogadaResumida[0]][jogadaResumida[2]] = '0';
                        tab[jogadaResumida[2]][jogadaResumida[3]] = 'P'; 
                        return 1;    
                    }              
            }
        }
    }
    if(tab[jogadaResumida[2]][jogadaResumida[3]] == 'r' || tab[jogadaResumida[2]][jogadaResumida[3]] == 'R'){
        if(jogada[0]<91) printf("Ganhou o branco!!\n");
        if(jogada[0]>91) printf("Ganhou o branco!!\n");
        return 2;
    }

    return 0;
}
int moveTorre(char **tab, char jogada[7]){
    int i, j, jogadaResumida[4];
    traduzirJogada(jogada, jogadaResumida);

    if(jogadaResumida[0] == jogadaResumida[2]){
        for(i = jogadaResumida[1]; i < jogadaResumida[3]; i++){
            if(tab[i][jogadaResumida[0]] != '0') return 0;
        }
        return 1;
    }
    if(jogadaResumida[1] == jogadaResumida[3]){
        for(j = jogadaResumida[0]; j < jogadaResumida[2]; j++){
            if(tab[jogadaResumida[1]][j] != '0') return 0;
        }
        return 1;
    }
    if(tab[jogadaResumida[2]][jogadaResumida[3]] == 'r' || tab[jogadaResumida[2]][jogadaResumida[3]] == 'R'){
        if(jogada[0]<91) printf("Ganhou o branco!!\n");
        if(jogada[0]>91) printf("Ganhou o branco!!\n");
        return 2;
    }

    return 0;
}
int moveBispo(char **tab, char jogada[7]){
    int i, j, jogadaResumida[4];
    traduzirJogada(jogada, jogadaResumida);

    if(jogadaResumida[0]-jogadaResumida[2] == jogadaResumida[1]-jogadaResumida[3]){
        for(i = 1; i < abs(jogadaResumida[0]-jogadaResumida[2]); i++){
            if(tab[jogadaResumida[0]+i][jogadaResumida[3]+i] != '0') return 0;
        }
        return 1;
    }
    if(tab[jogadaResumida[2]][jogadaResumida[3]] == 'r' || tab[jogadaResumida[2]][jogadaResumida[3]] == 'R'){
        if(jogada[0]<91) printf("Ganhou o branco!!\n");
        if(jogada[0]>91) printf("Ganhou o branco!!\n");
        return 2;
    }

    return 0;
}
int moveCavalo(char **tab, char jogada[7]){
    int i, j, jogadaResumida[4];
    traduzirJogada(jogada, jogadaResumida);

    if((jogadaResumida[0] == jogadaResumida[2] + 1 || jogadaResumida[0] == jogadaResumida[2] - 1) && (jogadaResumida[1] == jogadaResumida[3] + 2 || jogadaResumida[1] == jogadaResumida[3] - 2)){
        if(tab[jogadaResumida[2]][jogadaResumida[3]] == '0') return 1;
    }
    if((jogadaResumida[0] == jogadaResumida[2] + 2 || jogadaResumida[0] == jogadaResumida[2] - 2) && (jogadaResumida[1] == jogadaResumida[3] + 1 || jogadaResumida[1] == jogadaResumida[3] - 1)){
        if(tab[jogadaResumida[2]][jogadaResumida[3]] == '0') return 1;
    }
    if(tab[jogadaResumida[2]][jogadaResumida[3]] == 'r' || tab[jogadaResumida[2]][jogadaResumida[3]] == 'R'){
        if(jogada[0]<91) printf("Ganhou o branco!!\n");
        if(jogada[0]>91) printf("Ganhou o branco!!\n");
        return 2;
    }

    return 0;
}
int moveRei(char **tab, char jogada[7]){
    int i, j, jogadaResumida[4];
    traduzirJogada(jogada, jogadaResumida);

    if(jogadaResumida[0] == jogadaResumida[2] && (jogadaResumida[1] == jogadaResumida[3] - 1 || jogadaResumida[1] == jogadaResumida[3] + 1)){
                if(tab[jogadaResumida[2]][jogadaResumida[3]] == '0') return 1;
    }
    if(jogadaResumida[1] == jogadaResumida[3] && (jogadaResumida[0] == jogadaResumida[2] - 1 || jogadaResumida[0] == jogadaResumida[2] + 1)){
                if(tab[jogadaResumida[2]][jogadaResumida[3]] == '0') return 1;
    }
    if((jogadaResumida[1] == jogadaResumida[3]+1 || jogadaResumida[1] == jogadaResumida[3] - 1) && (jogadaResumida[0] == jogadaResumida[2] - 1 || jogadaResumida[0] == jogadaResumida[2] + 1)){
                if(tab[jogadaResumida[2]][jogadaResumida[3]] == '0') return 1;
    }
    if(tab[jogadaResumida[2]][jogadaResumida[3]] == 'r' || tab[jogadaResumida[2]][jogadaResumida[3]] == 'R'){
        if(jogada[0]<91) printf("Ganhou o branco!!\n");
        if(jogada[0]>91) printf("Ganhou o branco!!\n");
        return 2;
    }

    return 0;    
}
int moveRainha(char **tab, char jogada[7]){
    int i, j, jogadaResumida[4];
    traduzirJogada(jogada, jogadaResumida);

    if(tab[jogadaResumida[2]][jogadaResumida[3]] != '0'){     
        tab[jogadaResumida[0]][jogadaResumida[2]] = '0';
        tab[jogadaResumida[2]][jogadaResumida[3]] = 'P'; 
        return 1;    
    }
    if(tab[jogadaResumida[2]][jogadaResumida[3]] == 'r' || tab[jogadaResumida[2]][jogadaResumida[3]] == 'R'){
        if(jogada[0]<91) printf("Ganhou o branco!!\n");
        if(jogada[0]>91) printf("Ganhou o branco!!\n");
        return 2;
    }

    return 0;
}

int *traduzirJogada(char jogada[7], int *jogadaResumida[4]){
    if(jogada[1] == 'a') *jogadaResumida[0] = 0;
    if(jogada[1] == 'b') *jogadaResumida[0] = 1;
    if(jogada[1] == 'c') *jogadaResumida[0] = 2;
    if(jogada[1] == 'd') *jogadaResumida[0] = 3;
    if(jogada[1] == 'e') *jogadaResumida[0] = 4;
    if(jogada[1] == 'f') *jogadaResumida[0] = 5;
    if(jogada[1] == 'g') *jogadaResumida[0] = 6;
    if(jogada[1] == 'h') *jogadaResumida[0] = 7;

    if(jogada[2] == '8') *jogadaResumida[1] = 0;
    if(jogada[2] == '7') *jogadaResumida[1] = 1;
    if(jogada[2] == '6') *jogadaResumida[1] = 2;
    if(jogada[2] == '5') *jogadaResumida[1] = 3;
    if(jogada[2] == '4') *jogadaResumida[1] = 4;
    if(jogada[2] == '3') *jogadaResumida[1] = 5;
    if(jogada[2] == '2') *jogadaResumida[1] = 6;
    if(jogada[2] == '1') *jogadaResumida[1] = 7;

    if(jogada[4] == 'a') *jogadaResumida[2] = 0;
    if(jogada[4] == 'b') *jogadaResumida[2] = 1;
    if(jogada[4] == 'c') *jogadaResumida[2] = 2;
    if(jogada[4] == 'd') *jogadaResumida[2] = 3;
    if(jogada[4] == 'e') *jogadaResumida[2] = 4;
    if(jogada[4] == 'f') *jogadaResumida[2] = 5;
    if(jogada[4] == 'g') *jogadaResumida[2] = 6;
    if(jogada[4] == 'h') *jogadaResumida[2] = 7;

    if(jogada[5] == '8') *jogadaResumida[3] = 0;
    if(jogada[5] == '7') *jogadaResumida[3] = 1;
    if(jogada[5] == '6') *jogadaResumida[3] = 2;
    if(jogada[5] == '5') *jogadaResumida[3] = 3;
    if(jogada[5] == '4') *jogadaResumida[3] = 4;
    if(jogada[5] == '3') *jogadaResumida[3] = 5;
    if(jogada[5] == '2') *jogadaResumida[3] = 6;
    if(jogada[5] == '3') *jogadaResumida[3] = 7;

    return jogadaResumida;
}

char **reallocTab(char **tab){
    int i, j;
    tab = (char **) realloc(tab, 8 * sizeof(int*));
    if(tab == NULL){
        printf("Failed to allocate memory for the tab.\n");
        exit(1);
    }
    for(i = 0; i < 8; i++){
        tab[i] = (char *) realloc(tab[i], 8 * sizeof(int));
        if(tab[i] == NULL){
            printf("Failed to allocate memory for tab[%d].\n", i);
            exit(1);
        }
    }
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

    return tab;
}
void freeTab(char **tab){
    int i;
    for(i = 0; i < 8; i++){
        free(tab[i]);
    }
    free(tab);
}


int main(){
    char tab, jogada[7];
    int disponivel, jogadaResumida[4];

    FILE *arquivo = fopen("xadrez.bin", "rb");
    if(arquivo == NULL) exit(1);
    if(fread(&jogada, sizeof(jogada),1,arquivo) == 0) tab = reallocTab(tab);
    else{
        while(fread(&jogada, sizeof(jogada),1,arquivo) != 0){
            if(jogada[0] == 'p' || jogada[0] == 'P'){
                disponivel = movePeao(tab, jogada);
                if(disponivel == 2) remove(arquivo);
            }
            if(jogada[0] == 't' || jogada[0] == 'T'){
                disponivel = movePeao(tab, jogada);
                if(disponivel == 2) remove(arquivo);
            }
            if(jogada[0] == 'b' || jogada[0] == 'B'){
                disponivel = movePeao(tab, jogada);
                if(disponivel == 2) remove(arquivo);
            }
            if(jogada[0] == 'c' || jogada[0] == 'C'){
                disponivel = movePeao(tab, jogada);
                if(disponivel == 2) remove(arquivo);
            }
            if(jogada[0] == 'r' || jogada[0] == 'R'){
                disponivel = movePeao(tab, jogada);
                if(disponivel == 2) remove(arquivo);
            }
            if(jogada[0] == 'd' || jogada[0] == 'D'){
                disponivel = movePeao(tab, jogada);
                if(disponivel == 2) remove(arquivo);
            }
        }
    }       

    fclose(arquivo);
    freeTab(tab);

    return 0;
}

