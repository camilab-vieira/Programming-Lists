#include <stdio.h>

int main(){
    int d0, m0, a0, d1, m1, a1, t1=0;
    scanf("%d/%d/%d\n%d/%d/%d", &d0, &m0, &a0, &d1, &m1, &a1);
    
        if((m0==1||m0==3||m0==5||m0==7||m0==8||m0==10||m0==12)&&(m0!=m1||a0!=a1))
            t1= 31-d0;
        if((m0==4||m0==6||m0==9||m0==11)&&(m0!=m1||a0!=a1))
            t1= 30-d0;
        if(m0==2&&(m0!=m1||a0!=a1)){
            if(a0%4==0){
                if(a0%100==0){
                    if(a0%400==0)
                        t1= 29-d0;
                    else
                        t1= 28-d0;
                }
                else
                    t1= 29-d0;
            }
            else   
                t1= 28-d0;
        }
        t1+=d1;
        if(m0==m1&&a0==a1)
            t1-=d0;
        if(m0==1&&(m0!=m1||a0!=a1)){
            if(a0==a1&&m1==2){}
            else{
                if(a0%4==0){
                    if(a0%100==0 && a0%400==0)
                        t1++;
                    if(a0%100!=0)
                        t1++;
                }
            }
        }
        if(m1>1&&a0!=a1){
            if(a1%4==0){
                if(a1%100==0 && a1%400==0)
                    t1++;
                if(a1%100!=0)
                    t1++;
            }
        }
        if(a0==a1&&m0!=m1){
            m0++;
            for(int i=m0; i<m1; i++){
                if(i<=7){
                    if(i==2)
                        t1+= 28;
                    else{
                        if(i%2==0)
                            t1+= 30;
                        else
                            t1+= 31;
                    }
                }
                else{
                    if(i%2==0)
                            t1+= 31;
                    else
                        t1+= 30;
                }
            }
        }
        else{
                if(m0!=m1||a0!=a1){
                for(int i=1; i<m1; i++){
                    if(i<=7){
                        if(i==2)
                            t1+= 28;
                        else{
                            if(i%2==0)
                                t1+= 30;
                            else
                                t1+= 31;
                        }
                    }
                    else{
                        if(i%2==0)
                            t1+= 31;
                        else
                            t1+= 30;
                    }
                }
                for(int i=12; i>m0; i--){
                    if(i<=7){
                        if(i==2)
                            t1+=28;
                        else{
                            if(i%2==0)
                                t1+= 30;
                            else
                                t1+= 31;
                        }
                    }
                    else{
                        if(i%2==0)
                                t1+= 31;
                        else
                            t1+= 30;
                    }
                }
            }
        }
        if((a1-a0)>1){
            a1--;
            t1= t1+((a1-a0)*365);
            a0++;
            for(int i=a0; i<=a1; i++){
                if(i%4==0){
                    if(i%100==0 && i%400==0)
                        t1++;
                    if(i%100!=0)
                        t1++;
                }
            }
        }

    printf("%d", t1);
    return 0;
}