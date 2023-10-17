#include <iostream>
#include<queue>

using namespace std;

class Graph{
    private:
        int** matriz;
        bool* mark;
        int* dijkstra;
        int cnt;
    public:
        Graph(int node);
        void newGraph(int node);
        int first(int v);
        int next(int v, int w);
        void setEdge(int i, int j, int peso);
        void setMark(int v, bool val);
        bool getMark(int v);
        void Dijkstra(int s, int t);
};

Graph::Graph(int node){
    this->mark = new bool[20000];
    this->dijkstra = new int[20000];
    this->matriz = new int*[20000];
    for(int i = 0; i < 20000; i++) this->matriz[i] = new int[20000];
}

void Graph::newGraph(int node){
    this->cnt = node;
    for(int i = 0; i < this->cnt; i++){
        for(int j = 0; j < this->cnt; j++){
            this->matriz[i][j] = 50100;
        }
    }
    for(int j = 0; j < this->cnt; j++){
        this->mark[j] = false;
    }
    for(int i = 0; i < this->cnt; i++){
        this->dijkstra[i] = 50100;
    }
}

int Graph::first(int v){
    for(int i = 0; i < this->cnt; i++){
        if(this->matriz[v][i] != 50100) return i;
    }
    return this->cnt;
}

int Graph::next(int v, int w){
    for(int i = w + 1; i < this->cnt; i++){
        if(this->matriz[v][i] != 50100) return i;
    }
    return this->cnt;
}

void Graph::setEdge(int i, int j, int peso){
    if(this->matriz[i][j] > peso){
        this->matriz[i][j] = peso;
        this->matriz[j][i] = peso;
    }
    
}

void Graph::setMark(int v, bool val){
    this->mark[v] = val;
}

bool Graph::getMark(int v){
    return this->mark[v];
}

class comp{
public:
    bool operator() (pair<int,int>& v1, pair<int,int>& v2){
        return v1.second >= v2.second;
    }
};
void Graph::Dijkstra(int s, int t){
    int v, w;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> H; 
    pair<int,int>push;
    push.first = s;
    push.second = 0;
    H.push(push);
    this->dijkstra[s] = 0;
    v = s;
    for(int i = 0; i < this->cnt; i++) { 
        do{
            if(H.empty()) break;;
            v = (H.top()).first;
            H.pop();
        }while (getMark(v));
        
        this->setMark(v, true);
        for(w = first(v); w < this->cnt; w = next(v,w)){
            if(!(getMark(w))){
                if(this->dijkstra[w] > (this->dijkstra[v] + this->matriz[v][w])){
                    this->dijkstra[w] = this->dijkstra[v] + this->matriz[v][w];
                    push.first = w;
                    push.second = this->dijkstra[w];
                    H.push(push);
                }
            }
        }
        if(v == t) break;
    }
    if(this->dijkstra[t] < 50100) printf("%d\n", this->dijkstra[t]);
    else printf("unreachable\n");
}

int main(){
    int casos, tam, linhas, s, t, v1, v2, peso;
    scanf("%d", &casos);
    Graph graph(0);  
    for(int i = 0; i < casos; i++){
        scanf("%d %d %d %d", &tam, &linhas, &s, &t);
        graph.newGraph(tam);
        for(int j = 0; j < linhas; j++){
            scanf("%d %d %d", &v1, &v2, &peso);
            graph.setEdge(v1,v2,peso);
        }
        printf("Case #%d: ", i+1);
        graph.Dijkstra(s, t);
    }
}
