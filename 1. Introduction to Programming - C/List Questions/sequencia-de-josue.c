#include <stdio.h>

int main(){
    char a, b, c;
    char x, y, z;
    int v= 0;
    scanf("%c %c %c", &a, &b, &c);
    
    if((65>a || a>90) || (65>b || b>90) || (65>c || c>90))
        printf("Etiquetas erradas!\n");
    else{ 
        if(a==65 || a==69 || a==73 || a==79 || a==85)
            v++;
        if(b==65 || b==69 || b==73 || b==79 || b==85)
            v++;
        if(c==65 || c==69 || c==73 || c==79 || c==85)
            v++;

        if(a<b && a<c)
            x=a;
        else if((a>b && a<c) || (a>c && a<b))
            y=a;
        else if(a>b && a>c)
            z=a;
        if(b<a && b<c)
            x=b;
        else if((b>a && b<c) || (b>c && b<a))
            y=b;
        else if(b>a && b>c)
            z=b;
        if(c<a && c<b)
            x=c;
        else if((c>a && c<b) || (c>b && c<a))
            y=c;
        else if(c>b && c>a)
            z=c;    
        
        if(z-y>3 || y-x>3)
            printf("Só umas letras ai...\n");

        if(z-y==3 && y-x==3){
            if(v==0)
                printf("Trissequência perfeita.\n");
            else
                printf("Trissequência quase perfeita.\n");
        }
        else if(z-y==2 && y-x==2){
            if(v==0)
                printf("Bissequência perfeita.\n");
            else
                printf("Bissequência quase perfeita.\n");
        }
        else if(z-y==1 && y-x==1){
            if(v==0)
                printf("Sequência perfeita.\n");
            else
                printf("Sequência quase perfeita.\n");
        }
        else
            printf("Só umas letras ai...");
    }
    return 0;
}