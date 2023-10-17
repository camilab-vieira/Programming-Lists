#include <stdio.h>
#include <string.h>

int main(){
    int n,i;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        int m=0,j,k, q=0,l=0,h,p=0,r=0;
        scanf("%d",&m);
        int resp[m];
        char pes[m][100000],pres[100000],nome[100000]; 
        for(j=0;j<m;j++){
            scanf(" %s", pes[j]);
            resp[j]=0;
        } 
        for(j=0;j<m;j++){
            scanf(" %s", nome);
            scanf("%d", &q);
            scanf("%d", &l);
            p=q;
            if(l!=0){
                r=p%l;
                p/=l;
            }
            for(k=0;k<l;k++){
                scanf(" %s", pres);
                for(h=0; h<m; h++){
                    if(k==0&&!(strcmp(nome,pes[h]))){
                        resp[h]-=q;
                        resp[h]+=r;
                    }
                    if(!(strcmp(pres,pes[h]))){
                        resp[h]+=p;
                    }
                }
            }
        }
        for (j=0; j<m; j++){
            printf("%s %d\n", pes[j],resp[j]);
        }
        if(i<(n-1)){
            printf("\n");
        }
    }
    
    return 0;
}