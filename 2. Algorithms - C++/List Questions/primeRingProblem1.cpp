#include <iostream>

using namespace std;

class Backtracking{
    private:
        int primos[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    public:
        int* M;
        int num;
        Backtracking(int tam);
        bool backtracking(int l);
        bool valid(int l, int i);
        void print();

};

Backtracking::Backtracking(int tam){
    this->M = new int[tam];
}

bool primo(int num) {
    int i;
    for (i=2; i <= num/2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

bool Backtracking::valid(int l, int i){
    int numberEsq = 0, numberDir = 0, valido = 0, validoEsq = 0, validoDir = 0;
    if(this->M[i] != 0) return false;
    for(int j = 0; j < this->num; j++) {
        if(l == this->M[j]) return false;
    }
    if(i > 0) numberEsq = this->M[i-1];
    else if(i == 0) numberEsq = this->M[this->num-1];
    if(i < (this->num-1)) numberDir = this->M[i+1];
    else if(i == (this->num-1)) numberDir = this->M[0];
    /*while(i>0){
        if(!primo((this->M[i]+this->M[i-1]))) return false;
        i--;
    }*/
    for(int j = 0; j < 11 && !(validoEsq && validoDir); j++){   
        if(numberEsq){
            if(!primo((l + 1 + numberEsq))) return false;
            //== this->primos[j]) validoEsq = 1;
        }
        //else validoEsq = 1;
        if(numberDir){
            if(!primo((l + 1 + numberDir))) return false;
            // == this->primos[j]) validoDir = 1;
        }
       // else validoDir = 1;
    }
    //if(validoEsq && validoDir) return true;
    return true;
}

bool Backtracking::backtracking(int l){
    /*cout<<"l: "<<l<<endl;
    cout<<"teste "; print();*/
    if(l == this->num) print(); 
    for(int i = 1; i < this->num; i++){
        if(valid(l, i)){
            this->M[i] = l+1;
            if(backtracking(l + 1)) return true;
            else this->M[i] = 0;
        }
    }
    return false;
}

void Backtracking::print(){
    for(int j = 0; j < this->num; j++){
        cout<<this->M[j]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, i = 0, curr = 1;
    Backtracking bcktck(20);
    for(int i = 0; i < 20; i++){
        bcktck.M[i] = 0;
    }
    while(cin>>n){
        i++;
        bcktck.num = n;
        bcktck.M[0] = 1;
        cout<<"Case "<<i<<":"<<endl;
        bcktck.backtracking(1);
        cout<<endl;
    }
    return 0;
}