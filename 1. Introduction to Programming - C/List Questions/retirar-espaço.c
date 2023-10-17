#include <stdio.h>

int main(){
    char a[100];
    
    printf("Entre uma frase: \n");
    gets(a);

    for(int i=0; a[i];i++){
        switch (a[i])
        {
        case 32:
            a[i]= 10;
            break;
        default:
            break;
        }
    }

    printf("Frase:\n%s\n", a);
}