#include <stdio.h>
#include <string.h>

int main(){
    char inst[4], a, b;
    char inst1[4]={'m','o','v','\0'},inst2[4]={'a','d','d','\0'},inst3[4]={'s','u','b','\0'},inst4[4]={'a','n','d','\0'};
    int n,i;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%s %c, %c", inst, &a, &b);
        if(!(strcmp(inst, inst1))){
            printf("%c = %c\n",a,b);
        }
        if(!(strcmp(inst, inst2))){
            printf("%c += %c\n",a,b);
        }
        if(!(strcmp(inst, inst3))){
            printf("%c -= %c\n",a,b);
        }
        if(!(strcmp(inst, inst4))){
            printf("%c = %c & %c\n",a,a,b);
        }
    }
    
    return 0;
}