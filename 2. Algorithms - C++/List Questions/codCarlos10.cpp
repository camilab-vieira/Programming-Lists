#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <list>
#include <algorithm>

class MatrixGraph{
    private:
        short int numVertex;
        int numEdges;
        std::vector<bool> mark;
        void BFS(int start);
    public:
        int usedVertex;
        void setUsedVertex(int used);
        std::vector< std::vector<bool> > matrix;
        std::vector<int> pathSizes;
        MatrixGraph(int numVertex); 
        int getNumVertex(); 
        int getNumEdges(); 
        int first(int vertex);
        int next(int vertex, int w);
        void setEdge(int firstNode, int secondNode, int weight);
        void deleteEdge(int firstNode, int secondNode);
        void setMark(int vertex, bool mark);
        bool getMark(int vertex);
        void runBFS(int start);
};

MatrixGraph::MatrixGraph(int numVertex){
    this->matrix.resize(numVertex);
    for(int i = 0; i < numVertex; i++)
        this->matrix[i].resize(numVertex);
    
    // this->mark.resize(numVertex);
    this->numVertex = numVertex;
    // this->pathSizes.resize(numVertex);
    this->numEdges = 0;
}

int MatrixGraph::getNumVertex(){
    return this->numVertex;
}

int MatrixGraph::getNumEdges(){
    return this->numEdges;
}


int MatrixGraph::first(int vertex){
    for(int i = 0; i < this->usedVertex; i++){
        if(this->matrix[vertex][i] != 0)
            return i;
    }
    return this->numVertex; //retorno caso nao haja um prox nó
}

int MatrixGraph::next(int vertex, int w){
    for(int i = w+1; i < this->usedVertex; i++){
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

void MatrixGraph::BFS(int start){
    std::queue<int> auxQueue;
    auxQueue.push(start);
    this->setMark(start, true);
    while(auxQueue.size() > 0){
        int v = auxQueue.front();
        auxQueue.pop();
        //preVisit
        int w = this->first(v);
        while(w < this->usedVertex){
            if(!this->getMark(w)){
                this->setMark(w, true);
                auxQueue.push(w);//
                this->pathSizes[w] = this->pathSizes[v]+1;
            }
            w = this->next(v, w);
        }
        //posVisit
    }
    return;
}

//funcao adaptada
void MatrixGraph::runBFS(int start){
    for(int v = 0; v < this->usedVertex; v++){
        this->setMark(v, false);
    }
    this->BFS(start);
}

void MatrixGraph::setUsedVertex(int used){
    this->usedVertex = used;
    this->mark.resize(used);
    this->pathSizes.resize(used);

    for(int i = 0; i < pathSizes.size(); i++){
        pathSizes[i] = 400;
    }
}

struct Triple{
    std::string name;
    int index;
    int distance;
};

bool compareName(Triple t1, Triple t2){
    if(t1.name < t2.name)
        return true;
    else
        return false;
}

bool compareDist(Triple t1, Triple t2){
    if(t1.distance < t2.distance)
        return true;
    else
        return false;
}

int main(void){
    int numCases;
    scanf("%d", &numCases);

    for(int i = 0; i < numCases; i++){
        std::vector<Triple> relations;
        int vertexCount = 0;
        int numTeams;
        scanf("%d", &numTeams);
        MatrixGraph myGraph(300);
        
        for(int j = 0; j < numTeams; j++){
            char inputs[3][20];
            std::string students[3];
            int indexes[3];
            bool canAdd[3] = {true, true, true};

            for(int k = 0; k < 3; k++){
                scanf(" %s", inputs[k]);
                students[k] = inputs[k];
            }

            for(auto x:relations){
                if(x.name == students[0]){
                    canAdd[0] = false;
                    indexes[0] = x.index;
                }
                if(x.name == students[1]){
                    canAdd[1] = false;
                    indexes[1] = x.index;
                }
                if(x.name == students[2]){
                    canAdd[2] = false;
                    indexes[2] = x.index;
                }
            }

            for(int x = 0; x < 3; x++){
                if(canAdd[x]){
                    relations.push_back({students[x], vertexCount, 0});
                    indexes[x] = vertexCount++;
                }
            }

                myGraph.setEdge(indexes[0], indexes[1], 1);
                myGraph.setEdge(indexes[0], indexes[2], 1);
                myGraph.setEdge(indexes[1], indexes[2], 1);

        }

        myGraph.setUsedVertex(vertexCount);

        int ahmad;
        for(auto x: relations){
            if(x.name == "Ahmad")
                ahmad = x.index;
        }
        myGraph.pathSizes[ahmad] = 0;
        myGraph.runBFS(ahmad);
        
        //colocar as distancias nas relacoes
        for(int i = 0; i < relations.size(); i++){
            relations[i].distance = myGraph.pathSizes[relations[i].index];
        }

        std::stable_sort(relations.begin(), relations.end(), compareName);
        std::stable_sort(relations.begin(), relations.end(), compareDist);

        printf("%d\n", myGraph.usedVertex);
        for(auto x: relations){
            if(x.distance == 400)
                printf("%s undefined\n", x.name.c_str());
            else
                printf("%s %d\n", x.name.c_str(), x.distance);
        }
    }
    return 0;
}