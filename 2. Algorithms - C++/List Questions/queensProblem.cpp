#include <iostream>

using namespace std;

class Queens{
    private:
        int** M;
        int num;
    public:
        int printou;
        Queens(int tam);
        bool qns(int l);
        bool valid(int l, int i);
        void board();
        void clean();
        void print();

};

Queens::Queens(int tam){
    this->num = tam;
    this->printou = 0;
    this->M = new int*[10];
    for(int i = 0; i < 10; i++) this->M[i] = new int[10];
}

bool Queens::valid(int l, int i){
    bool value = true;
    for(int j = 0; j < this->num; j++){
        if(this->M[l][j] == 1) return false;
        if(this->M[j][i] == 1) return false;
        if(l+j < this->num && i+j < this->num)
            if(this->M[l+j][i+j] == 1) return false;
        if(l-j >= 0 && i-j >= 0)
            if(this->M[l-j][i-j] == 1) return false;
        if(l-j >= 0 && i+j < this->num)
            if(this->M[l-j][i+j] == 1) return false;
        if(l+j < this->num && i-j >= 0)
            if(this->M[l+j][i-j] == 1) return false;
    }
    //cout<<l<<" "<<i<<" "<<value<<endl;
    return true;
}

bool Queens::qns(int l){
    if(l == this->num){print(); this->printou = 1;}
    for(int i = 0; i < this->num; i++){
        if(valid(l, i)){
            this->M[l][i] = 1;
            if(qns(l + 1)) return true;
            else this->M[l][i] = 0;
        }
    }
    return false;
    
}

void Queens::print(){
    for(int j = 0; j < this->num; j++){
        for(int k = 0; k < this->num; k++){
            if(k < this->num - 1){
                if(this->M[j][k] == 1) cout<<"Q\t";
                else cout<<"-\t";
            }else{
                if(this->M[j][k] == 1) cout<<"Q";
                else cout<<"-";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n;
    while(cin>>n){
        Queens q(n);
        q.qns(0);
        if(!q.printou) cout<<"Not Possible\n";
    }
    return 0;
}