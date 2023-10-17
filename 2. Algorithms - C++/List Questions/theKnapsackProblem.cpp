#include<iostream>

using namespace std;

class Knapsack{
    private:
        int N;
        int C;
        int crr;
        int* I;
        int* W;
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
    this->crr = 1;
    this->I = new int[n+1];
    this->W = new int[n+1];
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
            if(i == 0 || j == 0) this->F[i][j] = 0;
            else if(this->W[i] <= j) this->F[i][j] = max(this->F[i-1][j], this->I[i]+this->F[i-1][j-this->W[i]]);
            else this->F[i][j] = this->F[i-1][j];;
        }
    }
    return this->F[this->N][this->C];
}

void Knapsack::push(int a, int b){
    this->I[this->crr] = b;
    this->W[this->crr] = a;
    this->crr++;
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
    int c, n, a, b;
    cin>>c>>n;
    Knapsack knpsck(n,c);
    
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        knpsck.push(a, b);
    }
    
    cout<<knpsck.knapsack()<<endl;
}