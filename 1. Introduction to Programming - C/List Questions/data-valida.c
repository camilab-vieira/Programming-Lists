#include <stdio.h>

int main(){
    int d, m, a;
    scanf("%d %d %d", &d, &m, &a);
    
    if(a<1900 || a>2100)
        printf("invalida");
    else{
        if(m<1 || m>12)
            printf("invalida");
        else{
            if(m==4 || m==6 || m==9 || m==11){
                if(d<=0 || d>30)
                    printf("invalida");
                else
                    printf("valida");
            }
            else{
                if(m==2){
                    if(d>0 && d<29)
                        printf("valida");
                    else{
                        if(d==29){
                            if(a%4==0){
                                if((a%100==0 && a%400==0) || a%100!=0)
                                    printf("valida");
                                else
                                    printf("invalida");
                            }
                            else
                                printf("invalida");
                        }
                        else
                            printf("invalida");
                    }
                }
                else{
                    if(d>0 && d<32)
                        printf("valida");
                    else
                        printf("invalida");
                }
            }
        }
    }
    return 0;
}