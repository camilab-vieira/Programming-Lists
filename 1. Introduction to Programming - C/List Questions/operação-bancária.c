#include <stdio.h>

int main(){
    double m[100][2], cred=0.0, deb=0.0, saldo=0.0;
    int i,j;
    
    for(i=0;(m[i-1][0])!=-1;i++){
        for(j=0; j<2; j++){
            if(j==0){
                scanf("%lf", &m[i][0]);
            }else{
                scanf("%lf", &m[i][1]);
            }
        }
    }
    for(i=0;(m[i-1][0])!=-1;i++){
        if(m[i][0]==0){
            deb+=m[i][1];
        }else{
            cred+=m[i][1];
        }
    }
    
    printf("Creditos: R$ %.2f\nDebitos: R$ %.2f\nSaldo: R$ %.2f\n", cred, deb, cred-deb);

    return 0;
}