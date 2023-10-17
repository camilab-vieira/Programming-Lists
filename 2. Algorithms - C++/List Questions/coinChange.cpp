#include <iostream>

using namespace std;
#define INFINITY 1000000

class Coin{
    private:
        int D[] = {1, 5, 10, 25, 50};
        int* F;
    public:
        int changeMaking(int n);
        int min(int a, int b);
};

int Coin::min(int a, int b){
    if(a < b) return a;
    else return b;
}

int Coin::changeMaking(int n){
    this->F = new int[n];
    this->F[0] = 0;
    int temp = INFINITY,
    for(int i = 1; i < n; i++){
         j = 0;
        while(j >= this->size && i >= this->D[j]){
            temp = min(this->F[i-this->D[j]], temp);
            j++;
        }
        this->F[i] = temp++;
    }
    return this->F[n];
}


int main(){
    int x;
    Coin c;
    while(cin>>x){
        cout<<c.changeMaking(x)<<endl;
    }
}