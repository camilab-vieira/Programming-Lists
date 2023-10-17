#include <stdio.h>

int main(){
    int l,c;
    scanf("%d %d",&l,&c);
    int mat[l][c],n,i,j,k,t=0,u=0,r=0,s=0,v=0,z=0;
    char dir[4]={'N','L','S','O'};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x,y,count=0;
        char d,inst[101];
        scanf("%d %d %c", &x,&y,&d);
        scanf(" %s",inst);
        while (inst[count]!='\0'){
            count++;
        }
        for(j=0;j<count&&v==0;j++){
            for(k=0;d!=dir[k];k++){}
            if(inst[j]=='D'){
                if(k<3){
                    d=dir[k+1];
                }else{
                    d=dir[0];
                }  
            }
            if(inst[j]=='E'){
                if(k>0){
                    d=dir[k-1];
                }else{
                    d=dir[3];
                }  
            }
            if(inst[j]=='F'){
                if(k==0){
                    if(y+1<c||r==0){
                        if(!(y+1<c)){
                            r=1;z=1;
                        }
                        y+=1;
                    }
                    
                }
                if(k==1){
                    if(x+1<l||s==0){
                        if(!(x+1<l)){
                            s=1;z=1;
                        }
                        x+=1;
                    }                 
                }
                if(k==2){
                    if(y-1>=0||t==0){
                        if(!(y-1>=0)){
                            t=1;z=1;
                        }
                        y-=1;
                    }              
                }
                if(k==3){
                    if(x-1>=0||u==0){
                        if(!(x-1>=0)){
                            u=1;z=1;
                        }
                        x-=1;
                    }
                }
            }
            if((t==1||u==1||r==1||s==1)&&z==1){
                printf("%d %d %c PERDIDO\n", x,y,d);
                v=1;
                z=0;
            }
        }
        if(v==0){
            printf("%d %d %c\n", x,y,d);
        }
        v=0;
    }

    return 0;
}