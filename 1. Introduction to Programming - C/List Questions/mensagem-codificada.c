#include <stdio.h>
#include <string.h>

int main(){
    char str[100000];
    int i,len;
    scanf(" %[^\n]", str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]=='4'){
            if(i==0||(i-2>=0&&str[i-2]=='.')){
                str[i]='A';
            }else{
                str[i]='a';
            }
        }
        if(str[i]=='5'){
            if(i==0||(i-2>=0&&str[i-2]=='.')){
                str[i]='E';
            }else{
                str[i]='e';
            }
        }
        if(str[i]=='1'){
            if(i==0||(i-2>=0&&str[i-2]=='.')){
                str[i]='I';
            }else{
                str[i]='i';
            }
        }
        if(str[i]=='0'){
            if(i==0||(i-2>=0&&str[i-2]=='.')){
                str[i]='O';
            }else{
                str[i]='o';
            }
        }
        if(str[i]=='2'){
            if(i==0||(i-2>=0&&str[i-2]=='.')){
                str[i]='U';
            }else{
                str[i]='u';
            }
        }
        if((i==0||(i-2>=0&&str[i-2]=='.'))&&str[i]>90){
            str[i]-=32;
        }
    }
    printf("%s",str);

    return 0;
}