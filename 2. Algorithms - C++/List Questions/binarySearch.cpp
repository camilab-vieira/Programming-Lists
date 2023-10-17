#include <iostream>

int BS(int A[], int caso, int size){
	int l = 0, r = (size - 1), m, indice; 
        while(l <= r){
            indice = (l + r)/2;
            if(caso == A[indice]){
            	while(caso == A[indice]){
            		indice--;
            	}indice++;
                return indice;
            } 
            else if(caso < A[indice]) r = indice - 1;
            else l = indice + 1;
        }
        return -1;
}
int main(){
    int i, size, qnt, caso;
    scanf("%d %d", &size, &qnt);
    int A[size];
    for(i = 0; i < size; i++){scanf("%d", &A[i]);}
    for(i = 0; i < qnt; i++){
        scanf("%d", &caso);
        printf("%d\n",BS(A, caso, size)); 
    }
}
/*
Sequential search
#include <iostream>

using namespace std;

int SS(int A[], int caso, int n){
	int i = 0;
	while(i < n && A[i] != caso)i++;
	if(i < n) return i;
 	else return - 1;
}

int main(){
    int i, size, qnt, caso;
    scanf("%d %d", &size, &qnt);
    int A[size];
    for(i = 0; i < size; i++) scanf("%d", &A[i]);
    for(i = 0; i < qnt; i++){
        scanf("%d", &caso);
        printf("%d\n",SS(A, caso, size)); 
    }
}*/