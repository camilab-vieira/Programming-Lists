#include <iostream>
#include <stack>

using namespace std;

class Graph{
    private:
        bool** matriz;
        int numEdge;
        bool* mark;
        int node;
        stack<int> s;
    public:
        Graph(int node);
        int first(int v);
        int next(int v, int w);
        void setEdge(int i, int j);
        void setMark(int v, bool val);
        bool getMark(int v);
        void graphTraverse();
        void toposort(int v);
        void print();
        void printStack();
};
Graph::Graph(int node){
    this->mark = new bool[node];
    this->matriz = new bool*[node];
    for(int i = 0; i < node; i++) this->matriz[i] = new bool[node];
    this->numEdge = 0;
    this->node = node;
    for(int i = 0; i < this->node; i++){
        for(int j = 0; j < this->node; j++){
            this->matriz[i][j] = false;
        }
    }
}

int Graph::first(int v){
    for(int i = 0; i < this->node; i++){
        if(this->matriz[v][i] == true) return i;
    }
    return this->node;
}

int Graph::next(int v, int w){
    for(int i = w + 1; i < this->node; i++){
        if(this->matriz[v][i] == true) return i;
    }
    return this->node;
}

void Graph::setEdge(int i, int j){
    if(this->matriz[i][j] == false){
        this->numEdge++;
        this->matriz[i][j] = true;
    }
}

void Graph::setMark(int v, bool val){
    this->mark[v] = val;
}

bool Graph::getMark(int v){
    return this->mark[v];
}

void Graph::graphTraverse(){
    for(int i = 0; i < this->node; i++){
        setMark(i, false);
    }
    for(int i = 0; i < this->node; i++){
        if(getMark(i) == false) toposort(i);
    } 
}
void Graph::toposort(int v = 0){
    int w;
    setMark(v, true);
    w = first(v);
    while(w < this->node){
        if(getMark(w) == false) toposort(w);
        w = next(v, w);
    }
    this->s.push(v);
}

void Graph::print(){
    for(int i = 0; i < this->node; i++){
        for(int j = 0; j < this->node; j++){
            cout<<this->matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void Graph::printStack(){
    int size = s.size();
    for(int i = 0; i < size; i++){
        cout<<this->s.top()<<endl;
        this->s.pop();
    }
}

int main(){
    int node, edge, j, k;
    cin>>node>>edge;
    Graph graph(node);
    for(int i = 0; i < edge; i++){
        cin>>j>>k;
        graph.setEdge(j, k);
    }
    graph.graphTraverse();
    graph.printStack();
    return 0;
}