#include <stdio.h>
#include <stdlib.h>

int soma(int a){
    a += a;
    return a;
}

int somaPonteiro(int *c){
    *c += *c;
    int a;
    a = *c + 2;
    return a;
}

void print(int *d, int *e){
    printf("%p e %p\n", d, e);
    printf("%d e %d\n", d, e);
    printf("%d e %d\n", *d, *e);
}

int main(){
    int a, b, c, d, e, f, v[3] = {0}, v1[3];

    a = 2;
    b = soma(a);
    printf("%d e %d\n", a, b); // 2 e 4

    c = 4;
    f = somaPonteiro(&c);
    printf("%d\n", c); //8
    printf("f: %d\n", f); //10

    /*d = 3; e = 2;
    printf("%p e %p\n", &d, &e);
    printf("%d e %d\n", &d, &e);
    printf("%d e %d\n", d, e);
    print(&d, &e);*/

    for(int i = 0; i < 3; i++){
        v[i] = i;
        printf("%d\n", *(v+i));
    }


    return 0;
}