#include <stdio.h>
#include <string.h>

int test(char str[101], char b, long int a);
int main(){
    char b, str[101];
    scanf(" %[^\n]", str);
    scanf(" %c", &b);
    long int a= strlen(str)-1;
    printf("%ld", test(str,b,a));
}
int test(char str[101], char b, long int a){
    int s=0;
    if(a<=0){
        if(str[a]==b){
            s+=1;
            return s;
        }
        else{
            s+=0;
            return s;
        }
    }
    else{
        if(str[a]==b){
            s++;
        }
        s+=test(str,b,(a-1));
        return s;
    }
}