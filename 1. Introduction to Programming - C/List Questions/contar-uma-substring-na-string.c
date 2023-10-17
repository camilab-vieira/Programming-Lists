#include <stdio.h>
#include <string.h>

int main(){
    char cat[100000], pal[100000];
    scanf(" %[^\n]\n %[^\n]", cat, pal);
    int i,j,len=(strlen(cat)),len1=(strlen(pal)),s=0,r=0,m=0,p=0;
    for(j=0;j<len;j++){
        m=j;
        while(pal[i]==cat[j]&&p==0){
            s++;
            if(i+1<len1){
                i++;
            }
            if(j+1<len){
                j++;
            }else{
                p=1;
            }
            if(s==len1){
                r++; i=0; s=0;p=1;
            }
        }
        s=0; j=m;i=0;p=0;
    }
    printf("%d\n",r);

    return 0;
}