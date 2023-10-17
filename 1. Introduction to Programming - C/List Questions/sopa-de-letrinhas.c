#include <stdio.h>
#include <string.h>

int main(){
    char letras[30];
    int n,i,j,h,k,s=0,resp=0,len,len1;
    scanf(" %[^\n]\n%d", letras, &n);
    len=strlen(letras);
    char palavras[n][30];
    for(h=0;h<n;h++){
        scanf(" %[^\n]", palavras[h]);
        len1= strlen(palavras[h]);
        s=0;
        for(i=0;i<len1;i++){
            for(j=0;j<len;j++){
               if(letras[j]==palavras[h][i]&&s<=len1){
                    if((i+1)<len1){
                        i++;j=-1;
                    }else{
                        j=len;i=len1;
                    }
                    s++;
                }
            }    
        }
        if(s==len1){
            resp++;
            for(i=0;i<len1;i++){
                for(j=0;j<len;j++){
                    if(letras[j]==palavras[h][i]){
                        letras[j]=NULL;
                        if((i+1)<len1){
                            i++;j=-1;
                        }else{
                            j=len;i=len1;
                        }
                    }
                }  
            }

        }               
    }
    printf("E possivel formar %d palavras com esse conjunto\n", resp);
    
    return 0;
}