#include <stdio.h>

int main(){
    int p1=0, p2=0, p3, c[8], c2[4], c3[4], i;
    for(i=0;i<8;i++){
        scanf("%d", &c[i]);
    }
    for(i=3; i>=0; i--){
        for(int j=0; j<(3-i);j++){
            c[i]*=2;
        }
        p1+=c[i];
    }
    for(i=7; i>=4; i--){
        for(int j=0; j<(7-i);j++){
            c[i]*=2;
        }
        p2+=c[i];
    }
    while(p1!=15){
        if(p1==0){
            for(i=4;i<8;i++){
                scanf("%d", &c[i]);
            }
            p2=0;
            for(i=7; i>=4; i--){
                for(int j=0; j<(7-i);j++){
                    c[i]*=2;
                }
                p2+=c[i];
            }
        }else{
            if(p1==2){
                printf("O registrador tem os seguintes valores:\nHigh: %d\nLow: %d\n",p1, p2);
            }else{ 
                if(p1==5){
                    printf("%d\n", p2*p2);
                }else{ 
                    if(p1==8){
                        printf("%X\n",p2);
                    }else{ 
                        if(p1==12){
                            scanf("%d", &p3);
                            printf("%d\n", p2*p3);
                        }else{
                            printf("ERRO: A instrucao nao existe.\n");
                        }
                    }
                }
            }
        }
        for(i=0;i<4;i++){
            scanf("%d", &c3[i]);
        }
        p1=0;
        for(i=3; i>=0; i--){
            for(int j=0; j<(3-i);j++){
                c3[i]*=2;
            }
            p1+=c3[i];
        }
    }
    return 0;
}