#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct Member{
    int pos;
    string name;
};

class Graph{
    private:
        bool** matriz;
        int numEdge;
        bool* mark;
        int* dijkstra;
        string* membros;
        int node;
        int cnt;
    public:
        Graph(int node);
        int first(int v);
        int next(int v, int w);
        void setEdge(int i, int j);
        void setMark(int v, bool val);
        bool getMark(int v);
        void Dijkstra();
        void print();
        void printAll();
        Member* createMember(string name);
        void setPos(string name1, string name2, string name3);
        int minVertex();
        int HoarePartitionName(string A[], int B[], int l, int r);
        void quicksortName(string A[], int B[], int l, int r);
        int HoarePartition(int A[], string B[], int l, int r);
        void quicksort(int A[], string B[], int l, int r);

};

Graph::Graph(int node){
    this->mark = new bool[node];
    this->membros = new string[node];
    this->matriz = new bool*[node];
    for(int i = 0; i < node; i++) this->matriz[i] = new bool[node];
    this->numEdge = 0;
    this->cnt = 1;
    this->node = node;
    for(int i = 0; i < this->node; i++){
        for(int j = 0; j < this->node; j++){
            this->matriz[i][j] = false;
        }
    }
}

Member* Graph::createMember(string name){
    int pos, s = 1;
    if(name == "Ahmad"){pos = 0;}
    else{
        pos = this->cnt;
        for(int i = 0; i < pos; i++){
            if(this->membros[i] == name){ s = 0; pos = i;}
        }
        if(s) this->cnt++;
    }
    Member *member;
    member = new Member;
    member->name = name;
    member->pos = pos;
    this->membros[pos] = name; 
    return member;
}

int Graph::first(int v){
    for(int i = 0; i < this->cnt; i++){
        if(this->matriz[v][i] == true) return i;
    }
    return this->cnt;
}

int Graph::next(int v, int w){
    for(int i = w + 1; i < this->cnt; i++){
        if(this->matriz[v][i] == true) return i;
    }
    return this->cnt;
}
void Graph::setPos(string name1, string name2, string name3){
    Member* member1 = createMember(name1);
    Member* member2 = createMember(name2);
    Member* member3 = createMember(name3);
    setEdge(member1->pos, member2->pos);
    setEdge(member1->pos, member3->pos);
    setEdge(member2->pos, member3->pos);
}
void Graph::setEdge(int i, int j){
    if(this->matriz[i][j] == false){
        this->numEdge++;
        this->matriz[i][j] = true;
        this->matriz[j][i] = true;
    }
}

void Graph::setMark(int v, bool val){
    this->mark[v] = val;
}

bool Graph::getMark(int v){
    return this->mark[v];
}

void Graph::print(){
    for(int i = 0; i < this->cnt; i++){
        for(int j = 0; j < this->cnt; j++){
            cout<<this->matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void Graph::printAll(){
    quicksort(this->dijkstra, this->membros, 0, (this->cnt - 1));
    int i = 0, k;
    while(i < this->cnt - 1){
        k = i;
        while(this->dijkstra[i] == this->dijkstra[i+1])i++;
        quicksortName(this->membros, this->dijkstra, k, i);
        i++;
    }
    cout<<this->cnt<<endl;
    for(int i = 0; i < this->cnt; i++){
        cout<<this->membros[i]<<" ";
        if(this->dijkstra[i] == this->cnt) cout<<"undefined"<<endl;
        else cout<<this->dijkstra[i]<<endl;
    }
}

void Graph::Dijkstra(){
    int v, w;
    queue<int> Q;
    Q.push(0);
    this->dijkstra = new int[this->cnt];
    for(int i = 0; i < this->node; i++){
        setMark(i, false);
    }
    for(int i = 0; i < this->cnt; i++){
        this->dijkstra[i] = this->cnt;
    }
    this->dijkstra[0] = 0;
    setMark(0, true);
    v = 0;
        for(int i = 0; i < this->cnt; i++) { 
            while(Q.size() > 0){
            v = Q.front();
            Q.pop();
            this->setMark(v, true);
            for(w = this->first(v); w < this->cnt; w = this->next(v,w)){
                if(this->dijkstra[w] > (this->dijkstra[v] + 1)) this->dijkstra[w] = this->dijkstra[v] + 1;
            }
            w = first(v);
            while(w < this->cnt){
                if(getMark(w) == false ){
                    setMark(w, true);
                    Q.push(w);
                }
                w = next(v, w);
            }
        }
    }
}
int Graph::minVertex() {
    int v, w;
    queue<int> Q;
    Q.push(0);
    setMark(0, true);
    while(Q.size() > 0){
        v = Q.front();
        Q.pop();
        w = first(v);
        while(w < this->cnt){
            if(getMark(w) == false ){
                setMark(w, true);
                Q.push(w);
            }
            w = next(v, w);
        }
    }
}

int Graph::HoarePartitionName(string A[], int B[], int l, int r){
    int Q = B[l], i = l, j = (r + 1), temp1;
    string p = A[l], temp;
    do{
        do{i++;}
        while(A[i] < p && i < r);
        do{j--;}
        while(A[j] > p);
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        temp1 = B[i];
        B[i] = B[j];
        B[j] = temp1;
    }while(i < j);
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    temp1 = B[i];
    B[i] = B[j];
    B[j] = temp1;
    temp1 = B[l];
    B[l] = B[j];
    B[j] = temp1;
    return j;
}

void Graph::quicksortName(string A[], int B[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartitionName(A, B, l, r);
        quicksortName(A, B, l, s - 1);
        quicksortName(A, B, s + 1, r);
    }
}

int Graph::HoarePartition(int A[], string B[], int l, int r){
    int p = A[l], i = l, j = (r + 1), temp;
    string Q = B[l], temp1;
    do{
        do{i++;}
        while(A[i] < p && i < r);
        do{j--;}
        while(A[j] > p);
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        temp1 = B[i];
        B[i] = B[j];
        B[j] = temp1;
    }while(i < j);
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    temp1 = B[i];
    B[i] = B[j];
    B[j] = temp1;
    temp1 = B[l];
    B[l] = B[j];
    B[j] = temp1;
    return j;
}

void Graph::quicksort(int A[], string B[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(A, B, l, r);
        quicksort(A, B, l, s - 1);
        quicksort(A, B, s + 1, r);
    }
}
/*
void Graph::MergeName(string A[], int B[], int l, int r){
    int i, j, k, m, temp1[r];
    string temp[r];
    for(i = l; i <= r; i++){temp[i] = A[i]; temp1[i] = B[i];}
    m = (l + r)/2;
    j = l; k = m + 1;
    cout<<"a";
    for(i = l; i <= r; i++){
        if(j == m + 1){A[i] = temp[k++]; B[i] = temp1[k++];}
        else if(k > r){ A[i] = temp[j++]; B[i] = temp1[j++];}
        else if(temp[k].compare(temp[j])){ A[i] = temp[j++]; B[i] = temp1[j++];}
        else{A[i] = temp[k++]; B[i] = temp1[k++];}
    }
    cout<<"b";
}
void Graph::MergesortName(string A[], int B[], int l, int r){
    int m;
    if(l < r){
        m = (l + r)/2;
        MergesortName(A, B, l, m); MergesortName(A, B, m + 1, r); MergeName(A, B, l, r);
    }
}*/

int main(){
    int casos, team, k;
    string members[3];
    cin>>casos;
    for(int i = 0; i < casos; i++){
        cin>>team;
        Graph graph(team*3);
        for(int j = 0; j < team; j++){
            cin>>members[0]>>members[1]>>members[2];
            graph.setPos(members[0],members[1],members[2]);
        }
        graph.Dijkstra();
        graph.printAll();
    }
    return 0;
}