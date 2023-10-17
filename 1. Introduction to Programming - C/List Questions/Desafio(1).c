#include <stdio.h>

int main(){
    char str1[256], str2[256];
    int strlen=0, i, j, strcmp=0;
    scanf("%[^\n]", str1);
    
    //strlen
    for(i=0;str1[i]!=0;i++){
        strlen++;
    }
    printf("%d\n", strlen);

   //strcpy
   for(i=0;str1[i]!=0;i++){
        str2[i]=0;
        str2[i]+=str1[i];
    }
    str2[i]=0;
    printf("%s\n", str2);

    //strcmp
    scanf(" %[^\n]", str2);
    for(i=0;str1[i]==str2[i];i++){}
    printf("%d\n", i);
    if(i>strlen){
        strcmp=0;
    }
    else{
        strcmp=str1[i]-str2[i];
    }
    printf("%d\n", strcmp);

    return 0;
}