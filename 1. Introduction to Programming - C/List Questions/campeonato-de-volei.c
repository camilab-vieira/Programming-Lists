#include <stdio.h>

int main(){
    int a, b, c, d, e, f, g, h;
    scanf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", &a, &b, &c, &d, &e, &f, &g, &h);
    
    if(a==c || a==e || a==g)
        printf("Alguem nao esta satisfeito...\n");
    else{ 
        if(b==a || b==d)
            printf("Alguem nao esta satisfeito...\n");
        else{ 
            if(g==h){
                if(d!=c)
                    printf("Alguem nao esta satisfeito...\n");
            }
            else{ 
                if(h!=g && h!=f)
                    printf("Alguem nao esta satisfeito...\n");
                else{ 
                    if(c==e){
                        if(f!=a)
                            printf("Alguem nao esta satisfeito...\n");
                    }
                    else{
                        if(c!=e){
                            if(f==a)
                                printf("Alguem nao esta satisfeito...\n");
                            else
                                printf("Conseguimos times suficientes!\n");
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}