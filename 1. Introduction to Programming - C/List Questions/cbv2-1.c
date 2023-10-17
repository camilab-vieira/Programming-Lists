#include <stdio.h>

int main(){
    char c = 'a'; 
    char *pc = &c;

    //a):
    printf("Endereco de c: %p\n", &c);
    printf("Valor guardado em c: %c\n", c);
    //b):
    printf("Valor de pc: %p\n", pc);
    printf("Valor guardado no endereco apontado por pc: %c\n", *pc);
    //c):
    printf("Endereco de pc: %p\n", &pc);
    //d):
    printf("Endereco do valor guardado no endereco apontado por pc: %p\n", &*pc);
    printf("Valor guardado no endereco de pc: %p\n", *&pc);
    /*e):
    O ponteiro é um tipo de variável utilizada para guardar o endereço de outra variável.
    Declarar uma variável significa atribuir um valor que ficará salvo no endereço de memória determinado.
    Por isso, o ponteiro, ao armazenar um endereço, tem acesso ao valor atribuído a tal endereço.
    Assim, o ponteiro pc aponta para o endereço de c, o qual guarda o valor de c.
    Logo, o valor guardado no endereco apontado por pc é o valor de c. Consequentemente, o endereço do valor guardado será o de c.
    E, o valor guardado no endereco de pc é o endereço de c, já que pc aponta para c.
    Ou seja, o endereço do valor guardado no endereço apontado por pc é o valor guardado no endereço de pc.
    */

    return 0;
}