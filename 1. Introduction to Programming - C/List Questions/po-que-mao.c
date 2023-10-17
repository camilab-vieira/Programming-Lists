#include <stdio.h>

int main(){
    int n, a, b, c;
    int x, y, z;
    int p=0;
    scanf("%d %d %d %d", &n, &a, &b, &c);

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
    if(b==c && b>a){
        x= a; 
        y= b;
        z= c;
    }
    else if(b==c && a>b){
        x= b;
        y= c;
        z= a;
    }
    if(a==b && c>a){
        x= a; 
        y= b;
        z= c;
    }
    else if(a==b && a>c){
        x= c;
        y= b;
        z= a;
    }
    if(a==c && b>a){
        x= a; 
        y= c;
        z= b;
    }
    else if(a==c && a>b){
        x= b;
        y= c;
        z= a;
    }
    if(a==b && a==c){
        x= a;
        y= b;
        z= c;
    }
        
    if(n-x>=0){
        n= n-x;
        p++;
    }
    if(n-y>=0){
        n= n-y;
        p++;
    }
    if(n-z>=0)
        p++;
    printf("%d", p);
    return 0;
}