#include <iostream>
#include <queue>
#include <stdio.h>
#include <list>

class MatrixGraph{
    private:
        short int numVertex;
        int numEdges;
        bool* mark;
        void BFS();
    public:
        int cnt;
        int usedVertex;
        void setUsedVertex(int used);
        bool** matrix;
        int* pathSizes;
        MatrixGraph(int numVertex); 
        int getNumVertex(); 
        int getNumEdges(); 
        int first(int vertex);
        int next(int vertex, int w);
        void setEdge(int firstNode, int secondNode, int weight);
        void deleteEdge(int firstNode, int secondNode);
        void setMark(int vertex, bool mark);
        bool getMark(int vertex);
        void runBFS();
};

MatrixGraph::MatrixGraph(int numVertex){
    this->mark = new bool[numVertex];
    this->pathSizes = new int[numVertex];
    this->matrix = new bool*[numVertex];
    for(int i = 0; i < numVertex; i++) this->matrix[i] = new bool[numVertex];
    this->numVertex = numVertex;
    this->numEdges = 0;
    for(int i = 0; i < numVertex; i++){
        for(int j = 0; j < numVertex; j++){
            this->matrix[i][j] = false;
        }
    }
}

int MatrixGraph::getNumVertex(){
    return this->numVertex;
}

int MatrixGraph::getNumEdges(){
    return this->numEdges;
}


int MatrixGraph::first(int vertex){
    for(int i = 0; i < this->cnt; i++){
        if(this->matrix[vertex][i] != 0)
            return i;
    }
    return this->numVertex; //retorno caso nao haja um prox nó
}

int MatrixGraph::next(int vertex, int w){
    for(int i = w+1; i < this->cnt; i++){
        if(this->matrix[vertex][i] != 0)
            return i;
    }
    return this->numVertex;
}

void MatrixGraph::setEdge(int firstNode, int secondNode, int weight){
    if(weight == 0)
        return;

    if(this->matrix[firstNode][secondNode] == 0)
        this->numEdges++;
    this->matrix[firstNode][secondNode] = true;
    this->matrix[secondNode][firstNode] = true;
}

void MatrixGraph::deleteEdge(int firstNode, int secondNode){
    if(this->matrix[firstNode][secondNode] != 0)
        this->numEdges--;

    this->matrix[firstNode][secondNode] = 0;
}

void MatrixGraph::setMark(int vertex, bool mark){
    if(mark != false && mark != true)
        return;
    
    this->mark[vertex] = mark;    
}

bool MatrixGraph::getMark(int vertex){
    return this->mark[vertex];
}

void MatrixGraph::BFS(){
    std::queue<int> auxQueue;
    auxQueue.push(0);
    this->setMark(0, true);
    while(auxQueue.size() > 0){
        int v = auxQueue.front();
        auxQueue.pop();
        //preVisit
        int w = this->first(v);
        while(w < this->cnt){
            if(!this->getMark(w)){
                this->setMark(w, true);
                auxQueue.push(w);//
                this->pathSizes[w] = this->pathSizes[v]+1;
            }
            w = this->next(v, w);
        }
        //posVisit
    }
}

void MatrixGraph::runBFS(){
    for(int v = 0; v < this->cnt; v++){
        this->setMark(v, false);
    }
    for(int i = 0; i < this->cnt; i++){
        pathSizes[i] = 400;
    }
    this->pathSizes[0] = 0;
    this->BFS();
}

struct Element{
    std::string name;
    int index;
    int distance;
};

int HoarePartitionName(Element A[], int l, int r){
    int i = l, j = (r + 1), temp1;
    std::string p = A[l].name;
    Element temp;
    do{
        do{i++;}
        while(A[i].name < p && i < r);
        do{j--;}
        while(A[j].name > p);
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }while(i < j);
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    return j;
}

void quicksortName(Element A[],  int l, int r){
    int s;
    if(l < r){
        s = HoarePartitionName(A, l, r);
        quicksortName(A, l, s - 1);
        quicksortName(A, s + 1, r);
    }
}

int HoarePartition(Element A[],  int l, int r){
    int p = A[l].distance, i = l, j = (r + 1);
    Element temp;
    do{
        do{i++;}
        while(A[i].distance < p && i < r);
        do{j--;}
        while(A[j].distance > p);
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }while(i < j);
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(Element A[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(A, l, r);
        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);
    }
}


int main(void){
    int numCases;
    scanf("%d", &numCases);

    for(int i = 0; i < numCases; i++){
        int vertexCount = 0;
        int numTeams;
        scanf("%d", &numTeams);
        MatrixGraph myGraph(numTeams*3);
        Element relations[numTeams*3];
        myGraph.cnt = 1;
        
        for(int j = 0; j < numTeams; j++){
            char inputs[3][20];
            std::string students[3];
            int indexes[3];
            bool canAdd[3] = {true, true, true};

            for(int k = 0; k < 3; k++){
                scanf(" %s", inputs[k]);
                students[k] = inputs[k];
                int pos, s = 1;
                if(students[k] == "Ahmad"){pos = 0;}
                else{
                    pos = myGraph.cnt;
                    for(int t = 0; t < pos; t++){
                        if(relations[t].name == students[k]){ s = 0; pos = t;}
                    }
                    if(s) myGraph.cnt++;
                }
                relations[pos].name = students[k];
                relations[pos].distance = 0;
                relations[pos].index = pos;
                indexes[k] = pos;
            }

            myGraph.setEdge(indexes[0], indexes[1], 1);
            myGraph.setEdge(indexes[0], indexes[2], 1);
            myGraph.setEdge(indexes[1], indexes[2], 1);                

        }

        myGraph.runBFS();
        
        //colocar as distancias nas relacoes
        for(int k = 0; k < myGraph.cnt; k++){
            relations[k].distance = myGraph.pathSizes[relations[k].index];
        }
        
        quicksort(relations, 0, myGraph.cnt - 1);
        int j = 0, k;
        while(j < myGraph.cnt - 1){
            k = j;
            while(relations[j].distance == relations[j+1].distance) j++;
            quicksortName(relations, k, j);
            j++;
        }

        printf("%d\n", myGraph.cnt);
        for(int k = 0; k < myGraph.cnt; k++){
            if(relations[k].distance == 400)
                printf("%s undefined\n", relations[k].name.c_str());
            else
                printf("%s %d\n", relations[k].name.c_str(), relations[k].distance);
        }
    }
    return 0;
}