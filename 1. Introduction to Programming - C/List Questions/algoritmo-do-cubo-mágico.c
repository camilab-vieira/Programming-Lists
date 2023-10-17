#include <stdio.h>
#include <string.h>

int main(){
    int count=0,i;
    char str[100][100];
    while(!(scanf(" %s", str[count])== EOF)){
        count++;
    }
    for(i=0;i<count;i++){
        if(str[i][1]=='\0'){
            str[i][1]=39;
            str[i][2]='\0';
        }else{
            if(str[i][1]==39){
                str[i][1]='\0';
            }
        }
    }
    for(i=(count-1);i>=0;i--){
        printf("%s ",str[i]);
    }

    return 0;
}