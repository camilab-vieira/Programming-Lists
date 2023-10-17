#include <stdio.h>
#include <string.h>

int main(){
    int n,i,j,h=-1,s=0,len,r=0,m=0,p=0,l=0;
    scanf("%d",&n);
    char str[13],a,cat[(6*n)+1], pal[1000];
    for(i=0;i<n;i++){
        scanf(" %c\n %[^\n]", &a, str);
        if(a=='d'){
            for(j=0;j<6;j++){
                h++; cat[h]=str[j]; 
            }
        }
        if(a=='e'){
            for(j=11;j>5;j--){
                h++;cat[h]=str[j];
            }
        }
    }
    scanf(" %[^\n]", pal);
    len=strlen(pal); i=0;
    for(j=0;j<6*n;j++){
        m=j;
        while(pal[i]==cat[j]&&l==0){
            s++;
            if(i+1<len){
                i++;
            }
            if(j+1<6*n){
                j++;
            }else{
                j=0;p=1;
            }
            if(s==len){
                r++; i=0; s=0;l=1;
                if(p==1){
                    p=0; l=1;
                }
            }
        }
        s=0; j=m;i=0;l=0;
    }
    i=len-1;
    for(j=0;j<6*n;j++){
        m=j;
        while(pal[i]==cat[j]&&l==0){
            s++;
            if(i-1>=0){
                i--;
            }
            if(j+1<6*n){
                j++;
            }else{
                j=0;p=1;
            }
            if(s==len){
                r++; i=len-1; s=0;l=1;
                if(p==1){
                    p=0; l=1;
                }
            }
        }
        s=0; j=m;i=len-1;l=0;
    }
    sprintf(pal,"%s%d",pal,r);
    printf("%s\n",pal);
    
    return 0;
}