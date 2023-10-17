#include <stdio.h>

int main(){
    int q, x, c, m, n, i, j, h;
    scanf("%d %d %d %d %d",&q,&x,&c,&m,&n);
    char v[c], m1[q][m][n];
    for(i=0;i<c;i++){
        scanf("%[^\n]", &v[i]);
    }
    for(h=0;h<q;h++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%c", &m1[h][i][j]);
            }
        }
    }
    /*for(i=0;i<c;i++){
        printf("%s\n",v[i]);
    }
    for(h=0;h<q;h++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%c", m1[h][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }*/

    return 0;
}

int main(){
    int q, x, c, m, n, g,h,i,j,k,l, t,u, tam=0,s=0,pal=0,resp=0;
    scanf("%d %d %d %d %d",&q,&x,&c,&m,&n);
    char v[c][20], m1[q][m][n];
    for(i=0;i<c;i++){
        scanf("%s", v[i]);
        for(j=0;v[i][j]!='\0';j++){
            if(v[i][j]<97){
                v[i][j]+=32;
            }
        }
    }
    for(h=0;h<q;h++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf(" %c", &m1[h][i][j]);
                if(m1[h][i][j]<97){
                    m1[h][i][j]+=32;
                }
            }
        }
    }
    for(h=0;h<q;h++){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                for(k=0;k<c;k++){
                    for(g=0;g<4;g++){
                        t=i;u=j;
                        for(l=0;v[k][l]!='\0';l++){
                            tam++;
                            if(m1[h][i][j]==v[k][l]){
                                s++;
                                if(g==0){
                                    if(i<m-1){
                                        i++;
                                    }
                                }
                                if(g==1){
                                    if(i>0){
                                        i--;
                                    }
                                }
                                if(g==2){
                                    if(j<n-1){
                                        j++;
                                    }
                                }
                                if(g==3){
                                    if(j>0){
                                        j--;
                                    }
                                }
                            }
                        }
                        if(tam==s){
                            pal++;
                        }
                        tam=0;s=0;
                        i=t;j=u;
                    }
                }
            }
        }
        if(pal<x){
            resp++;
        }
        pal=0;
    }
    printf("%d",resp);

    return 0;
}