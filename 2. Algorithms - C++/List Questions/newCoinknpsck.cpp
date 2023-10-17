#include<iostream>

using namespace std;

class Knapsack{
    private:
        int N;
        int C;
        int crr;
        int I[6] = {1, 1, 1, 1, 1, 1};
        int W[6] = {0, 1, 5, 10, 25, 50};
        int** F;
        int max(int a, int b);
    public:
        Knapsack(int n, int w);
        int knapsack();
        void push(int a, int b);
        void print();
};

Knapsack::Knapsack(int n, int c){
    this->N = n;
    this->C = c;
    this->F = new int*[n+1];
    for(int i = 0; i < n+1; i++){
        this->F[i] = new int[c+1];
    }
}
int Knapsack::max(int a, int b){
    if(a > b) return a;
    else return b;
}
int Knapsack::knapsack(){
    for(int i = 0; i < (this->N+1); i++){
        for(int j = 0; j < (this->C+1); j++){
            if(i == 0) this->F[i][j] = 0;
            else if(j == 0) this->F[i][j] = 1;
            else if(j < this->W[i]) this->F[i][j] = this->F[i-1][j];
            else this->F[i][j] = this->F[i-1][j] + this->I[i]+this->F[i-1][j-this->W[i]];
        }
    }
    return this->F[this->N][this->C];
}

void Knapsack::push(int a, int b){
    int c = 1;
    for(int i = 0; i < this->N+1; i++){
        this->I[i] = c; 
        this->W[i]= i;
        if(i == 4) c = 5;
        if(i == 9) c = 10;
        if(i == 24) c = 25;
        if(i == 49) c = 50;
    }
}

void Knapsack::print(){
    for(int i = 0; i < this->N+1; i++){
        cout<<this->I[i]<<" "<<this->W[i]<<endl;
    }
    for(int i = 0; i < this->N+1; i++){
        for(int j = 0; j < this->C+1; j++){
            cout<<this->F[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int c, n = 5, a, b;
    cin>>c;
    Knapsack knpsck(n,c);
    //cin>>a;
    knpsck.knapsack();
    knpsck.print();
}