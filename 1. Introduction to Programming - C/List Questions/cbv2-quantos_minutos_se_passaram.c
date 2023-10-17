#include <stdio.h>

int main()
{
    int h, m, t;

    printf("Digite a hora (formato 24h): ");
    scanf("%d", &h);
    printf("Digite os minutos: ");
    scanf("%d", &m);
    t=(h*60)+m;
    printf("%d minutos.\n", t);

    return 0;
}