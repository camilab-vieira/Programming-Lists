#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main(){
    int numString, tam;
    cin >> numString;
    char *strings[numString];
    for(int i = 0; i < numString; i++){
        cin >> tam;
        strings[i] = new char[tam + 1];
        cin.get(strings[i], (tam + 2));
    }
    
    for(int i = 0; i < numString; i++){
        int l = i;
        for(int j = i; j < numString; j++){
            if(strcmp(strings[i], strings[j]) > 0){
                i=j;
            }
        }
        char *aux = new char[sizeof(strings[i])];
        strcpy(aux, strings[i]);
        strings[i] = (char*)realloc(strings[i], sizeof(strings[l])*sizeof(char));
        strcpy(strings[i], strings[l]);
        strings[l] = (char*)realloc(strings[l], sizeof(aux)*sizeof(char));
        strcpy(strings[l], aux);
        i = l;
    }
    
    for(int i = 0; i < numString; i++){
        cout << strings[i] << endl;
    }
    
    return 0;
}