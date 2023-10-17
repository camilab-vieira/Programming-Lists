#include <stdio.h>

int main() {
    unsigned char c[100000];
    int count=0,i,t=0,m,j, s=1;
    while(scanf("%c", &c[count])!=EOF){
        count++;
    }
    for(i=0; i<count; i++){
        t=i;
        for(j=i;j<count;j++){
            if(c[i]>c[j]){
                i=j;
            }
        }
        m=c[t];
        c[t]=c[i];
        c[i]=m;
        i=t;
    }
    for(i=(count-1);i>=0;i--){
        if(i!=0){
            while(c[i]==c[i-1]){
                s++; 
                i--;
            }
            printf("%c %d\n", c[i], s);
            s=1;
        }
    }
    
	return 0;
}