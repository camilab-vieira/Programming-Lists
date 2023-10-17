#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<tuple>
#include<list>
#include<algorithm>

#define infinito 1000

using namespace std;

class comparador {

    public:
        bool operator() (tuple<int, int, int> &a, tuple<int, int, int> &b){
            return get<2>(a) > get<2>(b);
        }
};

class DS{
private:
    int* A;
public:
    DS(int size){
        this->A = new int[size];
        for(int i = 0; i < size; i++) 
            this->A[i] = -1;
    }
    int find(int curr){
        if(this->A[curr] == -1)
            return curr;
        this->A[curr] = find(this->A[curr]);
        return this->A[curr];
    }
    void uniao(int a, int b){
        int root1 = this->find(a);
        int root2 = this->find(b);
        if(root1 != root2)
            this->A[root2] = root1;
    }
};

class Graph{    
private:
    int* mark;
    int numEdges;
    int size;
public:
    int** matriz;
    int* array;
    Graph(int size);
    int first(int v);
    int next(int v, int w);
    void setEdge(int i, int j, int wt);
    void delEdge(int i, int j);
    void setMark(int v, int status);
    int getMark(int v);
    void setMark(int v);
    void printGraph();
    void kruskal(Graph &g);
    void contaGrandes(Graph mst);
};

int main(){

    int vertices = 1, arestas = 1;
    while (vertices != 0 && arestas != 0){

        // cout << "caso teste:" << endl;

        scanf("%d %d", &vertices, &arestas);
        if(vertices == 0 && arestas == 0) break;

        Graph g(vertices);

        for(int i = 0; i < arestas; i++){

            int start, end, wt;
            scanf("%d %d %d", &start, &end, &wt);

            g.setEdge(start, end, wt);
        }

        Graph mst(vertices);

        g.kruskal(mst);

        /*cout << "grafo: " << endl;
        g.printGraph();
        cout << "mst: " << endl;
        mst.printGraph();*/

        vector<int> grandoes;

        for(int i = 0; i < vertices; i++)
            for(int j = i+1; j < vertices; j++)
                if (g.matriz[i][j] != -1 && mst.matriz[i][j] == -1)
                    grandoes.push_back(g.matriz[i][j]);

        if(grandoes.empty()){
            cout << "forest";
        }else{
            sort(grandoes.begin(), grandoes.end());
            for(int i=0;i<grandoes.size();i++){  
                if(i < grandoes.size() - 1) cout<<grandoes[i]<<" ";
                else cout<<grandoes[i];
            }
        }

        cout << endl;

    }
         
}

Graph::Graph(int size){ 

    this->mark = new int[size];
    this->array = new int[size];
    this->size = size;
    this->matriz = new int*[size];
    for(int i = 0; i<this->size; i++)
       this->matriz[i] = new int[size];

    for(int i=0; i<this->size; i++)
        for(int j=0; j<this->size; j++)
            matriz[i][j] = -1;


    this->numEdges = 0;
}

int Graph::first(int v){

    for(int i = 0; i<this->size; i++)
        if(this->matriz[v][i] != -1) return i;
    return size;

}

int Graph::next(int v, int w){
    
    for(int i = w+1; i<this->size; i++)
        if(this->matriz[v][i] != -1) return i;
    return size;
    
}

void Graph::printGraph(){

    cout << "matriz:" << endl;
    for(int i = 0; i<this->size; i++){
        for(int j = 0; j<this->size; j++)
            cout << this->matriz[i][j] << " ";
        cout << endl;
    }

    // cout << "marcas" << endl;
    // for(int i = 0; i<this->size; i++)
    //     cout << this->mark[i] << endl;

}

void Graph::setEdge(int i, int j, int wt){
    // if (wt == 0)
    if(this->matriz[i][j] == -1) this->numEdges++;
    this->matriz[i][j] = wt;
    this->matriz[j][i] = wt;
}

void Graph::setMark(int v, int status){
    this->mark[v] = status;
}

int Graph::getMark(int v){
   return this->mark[v];
}

void Graph::kruskal(Graph &g){

    priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, comparador > H;

    for(int i = 0; i < this->size; i++){
        int w = first(i);
        while (w < this->size){
            H.push(make_tuple(i, w, this->matriz[i][w]));
            w = next(i,w);
        }
    }

    DS ds(this->size);
    int numMST = this->size;

    while (numMST > 1){
        if(H.empty()) break;
        int v = get<0>(H.top());
        int u = get<1>(H.top());
        int wt = get<2>(H.top());
        H.pop();
        
        if(ds.find(v) != ds.find(u)){
            ds.uniao(v, u);
            g.setEdge(v, u, wt);
            numMST--;
        }
    }
    
}