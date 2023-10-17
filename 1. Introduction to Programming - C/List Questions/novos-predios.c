#include <stdio.h>

int main(){
    int n, v[n], i, a=0, a1=0, a2=0, b=0,c=0,d=0,e=0, e1=0,e2=0;
    scanf(" %d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    e1=v[0];
    e2=v[0];
    for(i=0; i<n; i++){
        for(int j=0;j<n;j++){
            if(e1>v[j]){
                e1=v[j];
            }
            if(e2<v[j]){
                e2=v[j];
            }
        }
        for(int j=(i+1);j<n;j++){
            if(v[i]==v[j]){
                a1++;
            }
        }
        if(a1>0){
             a2++;
             a1=0;
        }
        if(v[i]>=100){
            b++;
        }
        if(v[i]>=50&&v[i]<100){
            c++;
        }
        if(v[i]<50){
            d++;
        }
    }
    e=e2-e1;
    a= n-a2;
    printf("%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e);
    return 0;
}