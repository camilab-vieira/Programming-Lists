#include <stdio.h>

int main(){
    int id1, id2, id3, id4, id5;
    int p1, p2, p3, p4, p5;
    int o1, o2, o3, o4, o5;
    int total, resultado;
    scanf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d", &id1, &p1, &id2, &p2, &id3, &p3, &id4, &p4, &id5, &p5, &total);

    if((id1%2==0) && (id1%3==0 || id1%5==0 || id1%7==0)){
        p1= p1*2;
        o1= id1*p1;
    }
    else{
        if(((id1*p1)%2!=0) && ((id1*p1)%11==0 || (id1*p1)%13==0 || (id1*p1)%17==0 || (id1*p1)%19==0))
            o1= id1*p1/2;   
        else{
            if(id1%17==0 && id1%2==0)
                o1= 0;
            else
                o1=id1*p1;
        }     
    }

    if((id2%2==0) && (id2%3==0 || id2%5==0 || id2%7==0)){
        p2= p2*2;
        o2= id2*p2;
    }
    else{
        if(((id2*p2)%2!=0) && ((id2*p2)%11==0 || (id2*p2)%13==0 || (id2*p2)%17==0 || (id2*p2)%19==0))
            o2= id2*p2/2;   
        else{
            if(id2%17==0 && id2%2==0)
                o2= 0;
            else
                o2=id2*p2;
        }     
    }

    if((id3%2==0) && (id3%3==0 || id3%5==0 || id3%7==0)){
        p3= p3*2;
        o3= id3*p3;
    }
    else{
        if(((id3*p3)%2!=0) && ((id3*p3)%11==0 || (id3*p3)%13==0 || (id3*p3)%17==0 || (id3*p3)%19==0))
            o3= id3*p3/2;   
        else{
            if(id3%17==0 && id3%2==0)
                o3= 0;
            else
                o3=id3*p3;
        }     
    }

    if((id4%2==0) && (id4%3==0 || id4%5==0 || id4%7==0)){
        p4= p4*2;
        o4= id4*p4;
    }
    else{
        if(((id4*p4)%2!=0) && ((id4*p4)%11==0 || (id4*p4)%13==0 || (id4*p4)%17==0 || (id4*p4)%19==0))
            o4= id4*p4/2;   
        else{
            if(id4%17==0 && id4%2==0)
                o4= 0;
            else
                o4=id4*p4;
        }     
    }

    if((id5%2==0) && (id5%3==0 || id5%5==0 || id5%7==0)){
        p5= p5*2;
        o5= id5*p5;
    }
    else{
        if(((id5*p5)%2!=0) && ((id5*p5)%11==0 || (id5*p5)%13==0 || (id5*p5)%17==0 || (id5*p5)%19==0))
            o5= id5*p5/2;   
        else{
            if(id5%17==0 && id5%2==0)
                o5= 0;
            else
                o5=id5*p5;
        }     
    }

    resultado= o1+o2+o3+o4+o5;

    if(resultado==total)
        printf("barra limpa, khan");
    else    
        printf("UEPAAA TEMOS UM RATINHO");
    return 0;
}