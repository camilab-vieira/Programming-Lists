#include <iostream>
#include <string.h>
 
using namespace std;
 
class Heap{
    private:
        int cnt;
        int* Array; 
        int crr;
    public:
        void create(int tam);
        void insert(int item);
        int findMin();       
        int removeMin();
};
 
void Heap::create(int tam){
    this->cnt = 0;
    this->Array = new int[tam];
    this->crr = 1;
}
void Heap::insert(int item){
    this->Array[this->crr] = item;
    this->cnt++;
    if(this->cnt > 1){
        int temp = this->crr;
        while(this->Array[temp] < this->Array[temp/2] && temp > 1){
            int aux = this->Array[temp];
            this->Array[temp] = this->Array[temp/2];
            this->Array[temp/2] = aux;
            temp = temp/2;
        }
    }
    this->crr++;
}
 
int Heap::findMin(){
    if(this->cnt == 0) return -16;
    return this->Array[1];
}

int Heap::removeMin(){
    if(this->cnt > 0) {
        this->Array[1] = this->Array[this->cnt];
        this->cnt--;
        this->crr--;
        int k = 1, v = this->Array[1];
        while(2*k <= this->cnt){
            int j = 2*k;
            if(j < this->cnt) if(this->Array[j] > this->Array[j + 1]) j++;
            if(v <= this->Array[j]) break;
            else{
                this->Array[k] = this->Array[j];
                k = j;
            }
        }
        this->Array[k] = v;
        return 1;
    }
    else return 0;
}     
 
int main(){

    int tam, item, crr = 0;
    char cmd[1000000], r[1000000][40];
    int cmd2[1000000];
    Heap heap;
    cin>>tam;
    heap.create(tam);
    for(int i = 0; i < tam; i++){
        scanf("%s", cmd);
        if(cmd[0] == 'i'){
            cin>>item;
            heap.insert(item);
            strcpy(r[crr], cmd);
            cmd2[crr] = item;
            crr++;
        }else if(cmd[0] == 'r'){
            if(heap.removeMin() == 0){
                strcpy(r[crr], "insert");
                cmd2[crr] = 0;
                crr++;
            }
            strcpy(r[crr],"removeMin");
            crr++;
        }else{
            cin>>item;
            while(item > heap.findMin() && heap.findMin() != -16){
                heap.removeMin();
                strcpy(r[crr],"removeMin");
                crr++;
            }
            if(item < heap.findMin() || heap.findMin() == -16){
                heap.insert(item);
                strcpy(r[crr],"insert");
                cmd2[crr] = item;
                crr++;
            }
            strcpy(r[crr], "getMin");
            cmd2[crr] = item;
            crr++;
        }
    }
    cout<<crr<<endl;
    for(int g=0;g<crr;g++){
        if(r[g][0]!='r'){
            printf("%s %d\n", r[g], cmd2[g]);
        }else{
            printf("%s\n", r[g]);
        }
    }
    return 0;
}