#include <stdio.h>

int main(){
    int l, c, i, j, h, k;
    scanf("%d %d", &l, &c);
    int m[l][c], m1[c][l];
    for(i=0; i<l; i++){
        for(j=0;j<c;j++){
            scanf("%d", &m[i][j]);
        }
    }
    for(i=0; i<c; i++){
        for(j=0;j<l;j++){
            m1[i][j]= m[j][i];
        }
    }
    for(i=0; i<c; i++){
        for(j=0;j<l;j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    return 0;
}