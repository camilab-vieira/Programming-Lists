#include <iostream>
#include <string>

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
    int temp = this->crr;
    while(this->Array[temp] < this->Array[temp/2] && temp > 1){
        int aux = this->Array[temp];
        this->Array[temp] = this->Array[temp/2];
        this->Array[temp/2] = aux;
        temp = temp/2;
    }
    this->crr++;
}

int Heap::findMin(){
    if(this->cnt == 0) return NULL;
    return this->Array[1];
}

int Heap::removeMin(){
    if(this->cnt > 0) {
        this->Array[1] = this->Array[this->cnt];
        this->cnt--;
        this->crr--;
        /*int temp = 1, temp1;
        while((this->Array[temp] > this->Array[temp*2] || this->Array[temp] > this->Array[temp*2 + 1])&& temp*2 < this->cnt){
            if(this->Array[temp*2] <= this->Array[(temp*2 + 1)]) temp1 = temp*2;
            else temp1 = (temp*2 + 1);
            int aux = this->Array[temp];
            this->Array[temp] = this->Array[temp1];
            this->Array[temp1] = aux;    
            temp = temp1;
        }*/
        for(int i = this->cnt/2; i > 0; i--){
            int k = i, v = this->Array[k], f = 0;
            while(!f && 2*k <= this->cnt){
                int j = 2*k;
                if(j < this->cnt) if(this->Array[j] < this->Array[j + 1]) j++;
                if(v >= this->Array[j]) f = 1;
                else{
                    this->Array[k] = this->Array[j];
                    k = j;
                }

            }
            this->Array[k] = v;
        }
        for(int i = i; i <=this->cnt; i++){
            cout<<this->Array[i]<<" ";
        }
        cout<<endl;
        return 1;
    }else return 0;
}     

int main(){
    int tam, item, crr = 0;
    string cmd, cmd2, r[10000];
    Heap heap;
    cin>>tam;
    heap.create(tam); 
    for(int i = 0; i < tam; i++){
        cin>>cmd;
        if(cmd == "insert"){
            cin>>cmd2;
            item = stoi(cmd2);
            heap.insert(item);
            r[crr].append("insert ");
            r[crr].append(cmd2);
            crr++;
        }else if(cmd == "removeMin"){
            if(heap.removeMin() == 0){
                r[crr].append("insert 0");
                crr++;
            }
            r[crr].append("removeMin");
            crr++;
        }else if(cmd == "getMin"){
            cin>>cmd2;
            item = stoi(cmd2);
            while(item > heap.findMin() && heap.findMin() != NULL){
                heap.removeMin();
                r[crr].append("removeMin");
                crr++;
            }
            if(item < heap.findMin() || heap.findMin() == NULL){
                heap.insert(item);
                r[crr].append("insert ");
                r[crr].append(cmd2);
                crr++;
            }
            r[crr].append("getMin ");
            r[crr].append(cmd2);
            crr++;
        }
    }
    cout<<crr<<endl;
    for(int i = 0; i < crr; i++){
        cout<<r[i]<<endl;
    }
    return 0;
}