#include <stdio.h>
#include <string.h>

int main(){
    int n,i,j,k,t,s,r=0,l=0,c=0;
    scanf("%d", &n);
    char mat[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf(" %c", &mat[i][j]);
        }    
    }
    scanf("%d", &k);
    for(i=0;i<k;i++){
        l=0;c=0;
        scanf("%d", &t);
        char inst[t+1];
        scanf(" %[^\n]", inst);
        s=0;
        for(j=0;j<=(t/2)-1;j++){
            if(inst[j]!=inst[t-j-1]){
                s=1;
            }
        }
        if(s==0){
            r++;
        }else{
            s=0;
            for(j=0;j<t;j++){
                if(inst[j]=='C'){
                    if(l-1>=0){
                        l--;
                        if(mat[l][c]=='0'){
                            s=1;
                        }
                        if(mat[l][c]=='x'&&j!=(t-1)){
                            mat[l][c]='0';
                        }
                    }else{
                        s=1;
                    }
                }
                if(inst[j]=='B'){
                    if(l+1<n){
                        l++;
                        if(mat[l][c]=='0'){
                            s=1;
                        }
                        if(mat[l][c]=='x'&&j!=(t-1)){
                            mat[l][c]='0';
                        }
                    }else{
                        s=1;
                    }
                }
                if(inst[j]=='D'){
                    if(c+1<n){
                        c++;
                        if(mat[l][c]=='0'){
                            s=1;
                        }
                        if(mat[l][c]=='x'&&j!=(t-1)){
                            mat[l][c]='0';
                        }
                    }else{
                        s=1;
                    }
                }
                if(inst[j]=='E'){
                    if(c-1>=0){
                        c--;
                        if(mat[l][c]=='0'){
                            s=1;
                        }
                        if(mat[l][c]=='x'&&j!=(t-1)){
                            mat[l][c]='0';
                        }
                    }else{
                        s=1;
                    }
                }
            }
            if(s==0){
                r++;
            }
        }
    }
    printf("%d\n",r);

    return 0;
}