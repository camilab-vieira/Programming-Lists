#include <stdio.h>

int main(){
    int n, m;
    int d, r,s;
    scanf("%d %d", &n, &m);
    
    d= m/100;
    r= m%100;
    if(r!=0)
        d++;
    d= d*100;
    s= n-d;
    
    if(m==0 || (s==0&&m==n))
            printf("Esta pago\nSobrou %d\n", s);
    else{
        if(s<0)
        printf("Pedro vai ter que fugir\n");
        else
            printf("Pegou mais\nEsta pago\nSobrou %d\n", s);
    }
    return 0;
}