#include <stdio.h>

int main(){
    int count=0,i,j,s=0,par=0,impar=0,r=0;
    char pal[101];
    while(scanf("%c", &pal[count])!=EOF){
    	count++;
    }
    for(i=0;i<(count-1);i++){
        for(j=i;j<(count-1);j++){
            if(pal[i]!=NULL&&pal[i]==pal[j]){
                s++;
                if(i!=j){
                    pal[j]=NULL;
                }
            }
            if(pal[i]==NULL){
                s=0;
            }
            if(pal[i]==32){
                s=0;
            }
        }
        if(s%2==0){
            par++;
        }else{
            impar++;
        }
        s=0;
    }
    if(impar>1){
        r=impar-1;
    }
    printf("%d",r);
}