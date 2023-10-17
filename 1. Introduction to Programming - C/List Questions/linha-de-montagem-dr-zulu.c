#include <stdio.h>

int main() {
    int n1, n2, count=0, i, t, m, j, s=0;
    int v1[100000], v2[100000], v3[100000], v4[100000];
    scanf("%d %d", &n1, &n2);
    for(i=0;i<n1;i++){
        scanf("%d", &v1[i]);
    }
    if(n2==0){
        printf("SEM RESPOSTA");
    }
    while(n2>0){
        scanf("%d ", &v2[count]);
        for(i=0;i<n1;i++){
            if(v2[count]==v1[i]){
                s++;
            }
        }
        count++;
        if(s==0){
            n2--;
        }
        s=0;
    }
    /*for(i=0;i<n1;i++){
        v3[i]=v1[i];
        if(i>0&&i<(n1-1)){
            v3[i]=(v1[i]*v1[i-1])-v1[i+1];
            v3[i]=abs(v3[i]);
        }
        if(i==n1-1&&i!=0){
            v3[i]=v1[i]*v1[i-1];
        }
    }*/
    for(i=0;i<count;i++){
        v4[i]=v2[i];
        if(i>0&&i<(count-1)){
            v4[i]=(v2[i]*v2[i-1])-v2[i+1];
            v4[i]=abs(v4[i]);
        }
        if(i==count-1&&i!=0){
            v4[i]=v2[i]*v2[i-1];
        }
    }
    for(i=0; i<count; i++){
        t=i;
        for(j=i;j<count;j++){
            if(v4[i]>v4[j]){
                i=j;
            }
        }
        m=v4[t];
        v4[t]=v4[i];
        v4[i]=m;
        i=t;
    }
    for(i=0;i<count;i++){
        s=0;
        for(j=0;j<n1;j++){
            if(v4[i]==v1[j]){
                s++;
            }
        }
        if(s==0){
            printf("%d ", v4[i]);
        }else{
            printf("DELETADO ");
        }
    }
    
	return 0;
}