#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef struct Key{
    string element;
    int value;
};

class Dictionary{
    private:
        int hashSize;
        int cnt;
        Key *H;
        int h(string K);
        int doubleH(int i, int value);
    public:
        void create(int size);
        void insert(string k); 
        Key find(string k); 
        void remove(string k);
        void printAll();
        void clear();
};

int Dictionary::h(string k){
    int soma = 0, i = 0;
    while (i < k.length()){
        i++;
        soma += i*k[i-1];
    }
    return fabs ((19*soma) % 101);
}

int Dictionary::doubleH(int i, int value){
    return fabs ((value + i*i + 23*i) % 101);
}

void Dictionary::create(int size){
    this->cnt = 0;
    this->hashSize = size;
    this->H = new Key[size];
}

void Dictionary::insert(string k){
    int pos, newPos, i = 0;
    Key key = find(k);
    if(this->cnt < this->hashSize && key.element == ""){   
        pos = key.value;
        if((this->H[pos]).element == "" && pos < 101){
            (this->H[pos]).element = k;
            (this->H[pos]).value = pos;
            this->cnt++;
        }
    }
}

Key Dictionary::find(string k){
    int pos, crrPos, newPos, s = 0, i = 0;
    Key key;
    pos = h(k);
    newPos = pos;
    crrPos = pos;
    while(i < 20){
        i++;
        if(this->H[newPos].element == "" && s == 0){crrPos = newPos; s = 1;}
        if(this->H[newPos].element == k){return this->H[newPos];}
        else{newPos = doubleH(i, pos);}
    }
    if(this->H[crrPos].element == ""){
        this->H[crrPos].value = crrPos; 
        return this->H[crrPos];
    }
    key.element = "!"; key.value = NULL; 
    return key;
}; 

void Dictionary::remove(string k){
    Key key = find(k);
    if((this->H[key.value]).element != ""){
        (this->H[key.value]).element = "";
        this->cnt--;
    }
};

void Dictionary::printAll(){
    cout<<this->cnt<<"\n";
    for(int i = 0; i < this->hashSize; i++){
        if((this->H[i]).element != "" && (this->H[i]).element != "!"){
            cout<<(this->H[i]).value<<":"<<(this->H[i]).element<<"\n";
        }
    }
};

void Dictionary::clear(){
    delete[] this->H;
    this->cnt = 0;
};

int main(){
    int i, j, casos, numOp;
    string comandos, comando[2];
    while(cin>>casos){
        Dictionary d[casos];
        for(i = 0; i < casos; i++){
            d[i].create(101);
            cin>>numOp;
            for(j = 0; j < numOp; j++){
                cin>>comandos;comando[0] = comandos.substr(0, 3);
                comando[1] = comandos.substr(4);
                if(comando[0] == "ADD"){
                    d[i].insert(comando[1]);
                }if(comando[0] == "DEL"){
                    d[i].remove(comando[1]);
                }
                
            d[i].printAll();
            }
            //d[i].printAll();
            d[i].clear();
        }
    }
    return 0;
}