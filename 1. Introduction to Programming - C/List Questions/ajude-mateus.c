#include <stdio.h>

int main(){
    int n, x0, x1, y0, y1, z0, z1;
    int t=0;
    scanf("%d\n%d %d %d %d %d %d", &n, &x0, &x1, &y0, &y1, &z0, &z1);

    t= x0+y0+z0;
    if(t==n)
        printf("S\n%d %d %d", x0, y0, z0);
    if(t>n)
        printf("N");
    if(t<n){
        if((y1-y0)>(n-t))
            printf("S\n%d %d %d", x0, y0+(n-t), z0);
        else{
            if(((y1-y0)+(z1-z0))>(n-t))
                printf("S\n%d %d %d", x0, y1, z0+(n-t-(y1-y0)));
            else{
                if(((x1-x0)+(y1-y0)+(z1-z0))>(n-t))
                    printf("S\n%d %d %d", x0+(n-t-(z1-z0)-(y1-y0)), y1, z1);
                else
                    printf("N");
            }            
            

        }
    }
    return 0;
}