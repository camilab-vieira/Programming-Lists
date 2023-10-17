#include <stdio.h>
#include <string.h>

int main(){
    char str[301];
    scanf(" %[^\n]", str);
    int tam= strlen(str),i,s=0;
    for(i=0;i<tam;i++){
        if(str[i]==32){
            s++;
        }else{
            s=0;
        }
        if(s<=1){
            printf("%c",str[i]);
        }
    }

    return 0;
}