#include <stdio.h>

int main(){
char b[100];

    printf("Entre uma frase: \n");
    scanf("%[^\n]", &b);
    printf("%s", b);
}