#include <iostream>
#include <bits/stdc++.h>
#define reset INT_MAX

using namespace std;

class Graph{
    private:
        pair<int,int>** matriz;
        int cnt;
    public:
        Graph(int node);
        int first(int v);
        int next(int v, int w);
        void setEdge(int i, int j, int peso);
        void Kruskal(Graph *g);
        void print();
        void printGraph();
};

Graph::Graph(int node){
    this->cnt = node + 1;
    this->matriz = new pair<int,int>*[node + 1];
    for(int i = 0; i < this->cnt; i++) this->matriz[i] = new pair<int,int>[node + 1];
    for(int i = 0; i < this->cnt; i++){
        for(int j = 0; j < this->cnt; j++){
        	pair<int, int> aux;
	    	aux.first = reset;
	    	aux.second = 0;
            this->matriz[i][j] = aux;
        }
    }
}

int Graph::first(int v){
    for(int i = 0; i < this->cnt; i++){
        if(this->matriz[v][i].first != reset) return i;
    }
    return this->cnt;
}

int Graph::next(int v, int w){
    for(int i = w + 1; i < this->cnt; i++){
        if(this->matriz[v][i].first != reset) return i;
    }
    return this->cnt;
}

void Graph::setEdge(int i, int j, int peso){
    if(this->matriz[i][j].first > peso){
        pair<int, int> aux;
    	aux.first = peso;
    	aux.second = 0;
        this->matriz[i][j] = aux;
        this->matriz[j][i] = aux;
    }
    
}

void Graph::print(){
    int ord[10001], curr = 0;
    for(int i = 0; i < this->cnt; i++){
        for(int j = i+1; j < this->cnt; j++){
            if(this->matriz[i][j].first != reset && this->matriz[i][j].second == 0){
                ord[curr] = this->matriz[i][j].first; 
                curr++;
            }
        }
    }
    if(curr == 0) cout<<"forest";
    else{
        sort(ord, ord + curr);
        for(int i = 0; i < curr; i++){
            cout<<ord[i];
            if(i != curr - 1) cout<<" ";
        }
    }
  cout<<endl;
}

struct trio{
    int first, second, third;
};
class comp{
public:
    bool operator() (trio &v1, struct trio &v2){
        return v1.third > v2.third;
    }
};
class disjointSubset{
    private:
    public:
        int array[1001];
        disjointSubset(int n);
        int find(int curr);
        void unionFunc(int a, int b);
};
disjointSubset::disjointSubset(int n){
    for(int i = 0; i < n; i++){
        this->array[i] = -1;
    }
}
int disjointSubset::find(int curr){
    if(this->array[curr] == -1) return curr;
    this->array[curr] = find(this->array[curr]);
    return this->array[curr];
}
void disjointSubset::unionFunc(int a, int b){
    int root1, root2;
    root1 = find(a);
    root2 = find(b);
    if(root1 != root2){
        this->array[root2] = root1;
    }
}
void Graph::Kruskal(Graph *g){
    int w, numMST;
    disjointSubset ds(this->cnt);
    priority_queue<trio, vector<trio>, comp> H; 
    trio aux;   
    for(int i = 0; i < this->cnt; i++){
        w = first(i);
        while(w < this->cnt){
            aux.first = i;
            aux.second = w;
            aux.third = this->matriz[i][w].first;
            H.push(aux);
            w = next(i, w);
        }
    }
    numMST = this->cnt;

  while(numMST > 1 && !(H.empty())){
        aux = H.top();
        H.pop();
        if(ds.find(aux.first) != ds.find(aux.second)){
            ds.unionFunc(aux.first, aux.second);
            g->setEdge(aux.first, aux.second, aux.third);
            this->matriz[aux.first][aux.second].second = 1;
            this->matriz[aux.second][aux.first].second = 1;
            numMST--;
        }
    }
    print();
}
void Graph::printGraph(){

    // cout << "matriz:" << endl;
    for(int i = 0; i<this->cnt; i++){
        for(int j = 0; j<this->cnt; j++){
            if(this->matriz[i][j].first == reset) cout<<"0 ";
            else cout << this->matriz[i][j].first << " ";
        }
        cout << endl;
    }

    // cout << "marcas" << endl;
    // for(int i = 0; i<this->size; i++)
    //     cout << this->mark[i] << endl;

}

int main(){
    int nodes, edges, v1, v2, peso;
    scanf("%d %d", &nodes, &edges);
    while(nodes != 0 && edges != 0){
        Graph graph(nodes);  
        for(int j = 0; j < edges; j++){
            scanf("%d %d %d", &v1, &v2, &peso);
            graph.setEdge(v1,v2,peso);
        }
        Graph g(nodes);  
        graph.Kruskal(&g);
    	scanf("%d %d", &nodes, &edges);
    }
  return 0;
}