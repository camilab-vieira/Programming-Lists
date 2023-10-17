#include <stdio.h>
#include <string.h>

int main(){
    int tam, i,j,k, valido=1,somatorio=0;
    printf("Digite a dimensao da matriz: ");
    scanf("%d", &tam);
    char matriz[tam][tam][31], somatorio_str[100000], senha[100000];
    printf("Digite agora as %d strings que comporao a matriz %d x %d: \n", (tam*tam), tam, tam);
    //recebendo a matriz
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            scanf("%s", matriz[i][j]);
        }
    }
    //checando as condições
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            //checando a condição da diagonal principal
            if(i==j){
                //checando tamanho
                if(strlen(matriz[i][j])!=(i+j+1)&&valido==1){
                    printf("Propriedade nao satisfeita.");
                    valido=0; 
                }
                //checando vogais minúsculas
                else{
                    for(k=0;matriz[i][j][k]!='\0'&&valido==1;k++){
                        if(matriz[i][j][k]!=97&&matriz[i][j][k]!=101&&matriz[i][j][k]!=105&&matriz[i][j][k]!=111&&matriz[i][j][k]!=117){
                            printf("Propriedade nao satisfeita.");
                            valido=0;
                        }
                    }
                }
            }
            //checando os demais elementos
            else{
                for(k=0;matriz[i][j][k]!='\0'&&valido==1;k++){
                    if(matriz[i][j][k]>90||matriz[i][j][k]==65||matriz[i][j][k]==69||matriz[i][j][k]==73||matriz[i][j][k]==79||matriz[i][j][k]==85){
                        printf("Propriedade nao satisfeita.");
                        valido=0;
                    }
                }
            }
        }
    }
    //concatenando
    if(valido==1){
        for(i=0;i<tam;i++){
            for(j=0;j<tam;j++){
                //diagonal principal
                if(i==j){
                    strcat(senha, matriz[i][j]);
                }
                //demais elementos
                else{
                    for(k=0;matriz[i][j][k]!='\0';k++){
                        somatorio+=matriz[i][j][k];
                    }
                    sprintf(somatorio_str,"%d",somatorio);
                    somatorio=0;
                    strcat(senha, somatorio_str);
                }
            }
        }
        printf("%s", senha);
    }
 
    return 0;
}