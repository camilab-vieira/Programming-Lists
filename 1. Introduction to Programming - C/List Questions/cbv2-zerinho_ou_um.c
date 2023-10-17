#include <stdio.h>

int main(){
    int A, B, C;

    printf("Alice: ");
    scanf("%d", &A);
    printf("Beto: ");
    scanf("%d", &B);
    printf("Clara: ");
    scanf("%d", &C);
    
    if(A==B && A==C)
        printf("*\n");   
    else{
        if(A==B)
            printf("C\n");
        else{
            if(A==C)
                printf("B\n");
            else
                printf("A\n");
        }
    }
    return 0;
}