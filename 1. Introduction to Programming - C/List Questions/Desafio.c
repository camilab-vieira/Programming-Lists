#include <stdio.h>

int main(){
    char str1[256], str2[256];
    int s=0, i, j;
    scanf("%[^\n]", str1);
    printf("AAAA");
    for(i=0;str1[i]!=0;i++){
        s++;
    }

    printf("%d", s);

    return 0;
}