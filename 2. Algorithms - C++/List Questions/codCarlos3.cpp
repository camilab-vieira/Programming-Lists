#include <iostream>
#include <queue>
#include <stdio.h>
#include <list>
#include <string>

using namespace std;

typedef struct Member{
    int pos;
    string name;
};

class MatrixGraph{
    private:
        short int numVertex;
        int numEdges;
        bool* mark;
    public:
        void BFS(int start);
        int usedVertex;
        string* membros;
        bool** matrix;
        //std::vector<int> pathSizes;
        int* pathSizes;
        MatrixGraph(int numVertex); 
        int first(int vertex);
        int next(int vertex, int w);
        void setEdge(int firstNode, int secondNode);
        void setMark(int vertex, bool mark);
        bool getMark(int vertex);
        Member* createMember(string name);
        void setPos(string name1, string name2, string name3);
};

MatrixGraph::MatrixGraph(int numVertex){
    /*this->matrix.resize(numVertex);
    for(int i = 0; i < numVertex; i++)
        this->matrix[i].resize(numVertex);
    */
    // this->mark.resize(numVertex);
    //this->numVertex = 300;
    // this->pathSizes.resize(numVertex);
    //this->numEdges = 0;
    //this->usedVertex = 1;
    /*for(int i = 0; i < numVertex; i++){
        for(int j = 0; j < numVertex; j++)
            this->matrix[i][j] = false;
    }*/
    this->mark = new bool[numVertex];
    this->membros = new string[numVertex];
    this->matrix = new bool*[numVertex];
    for(int i = 0; i < numVertex; i++) this->matrix[i] = new bool[numVertex];
    this->numEdges = 0;
    this->usedVertex = 1;
    for(int i = 0; i < numVertex; i++){
        for(int j = 0; j < numVertex; j++){
            this->matrix[i][j] = false;
        }
    }
}

/*int MatrixGraph::getNumVertex(){
    return this->numVertex;
}

int MatrixGraph::getNumEdges(){
    return this->numEdges;
}*/


int MatrixGraph::first(int vertex){
    for(int i = 0; i < this->usedVertex; i++){
        if(this->matrix[vertex][i] == true)
            return i;
    }
    return this->usedVertex; //retorno caso nao haja um prox nó
}

int MatrixGraph::next(int vertex, int w){
    for(int i = w+1; i < this->usedVertex; i++){
        if(this->matrix[vertex][i] != 0)
            return i;
    }
    return this->usedVertex;
}

/*void MatrixGraph::setEdge(int firstNode, int secondNode, int weight){
    if(weight == 0)
        return;

    if(this->matrix[firstNode][secondNode] == 0)
        this->numEdges++;
    this->matrix[firstNode][secondNode] = true;
    this->matrix[secondNode][firstNode] = true;
}*/

/*void MatrixGraph::deleteEdge(int firstNode, int secondNode){
    if(this->matrix[firstNode][secondNode] != 0)
        this->numEdges--;

    this->matrix[firstNode][secondNode] = 0;
}*/

void MatrixGraph::setMark(int vertex, bool mark){
    this->mark[vertex] = mark;    
}

bool MatrixGraph::getMark(int vertex){
    return this->mark[vertex];
}

Member* MatrixGraph::createMember(string name){
    int pos, s = 1;
    if(name == "Ahmad"){pos = 0;}
    else{
        pos = this->usedVertex;
        for(int i = 0; i < pos; i++){
            if(this->membros[i] == name){ s = 0; pos = i;}
        }
        if(s) this->usedVertex++;
    }
    Member *member;
    member = new Member;
    member->name = name;
    member->pos = pos;
    this->membros[pos] = name; 
    return member;
}
void MatrixGraph::setPos(string name1, string name2, string name3){
    Member* member1 = createMember(name1);
    Member* member2 = createMember(name2);
    Member* member3 = createMember(name3);
    setEdge(member1->pos, member2->pos);
    setEdge(member1->pos, member3->pos);
    setEdge(member2->pos, member3->pos);
}
void MatrixGraph::setEdge(int i, int j){
    if(this->matrix[i][j] == false){
        this->numEdges++;
        this->matrix[i][j] = true;
        this->matrix[j][i] = true;
    }
}

void MatrixGraph::BFS(int start){
    int v, w;
    queue<int> Q;
    Q.push(0);
    this->pathSizes = new int[this->usedVertex];
    for(int i = 0; i < this->usedVertex; i++){
        setMark(i, false);
    }
    for(int i = 0; i < this->usedVertex; i++){
        this->pathSizes[i] = this->usedVertex;
    }
    this->pathSizes[0] = 0;
    setMark(0, true);
    v = 0;
    while(Q.size() > 0){
        v = Q.front();
        Q.pop();
        for(w = this->first(v); w < this->usedVertex; w = this->next(v,w)){
            if(this->pathSizes[w] > (this->pathSizes[v] + 1)) this->pathSizes[w] = this->pathSizes[v] + 1;
        }
        w = first(v);
        while(w < this->usedVertex){
            if(getMark(w) == false ){
                setMark(w, true);
                Q.push(w);
            }
            w = next(v, w);
        }
    }
}

//funcao adaptada
/*void MatrixGraph::runBFS(int start = 0){
    for(int v = 0; v < this->usedVertex; v++){
        this->setMark(v, false);
    }
    this->BFS(start);
}
*/
/*void MatrixGraph::setUsedVertex(int used){
    this->usedVertex = used;
    this->mark.resize(used);
    //this->pathSizes.resize(used);

    for(int i = 0; i < this->usedVertex; i++){
        pathSizes[i] = 400;
    }
}*/
/*
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
}*/


int HoarePartitionName(string A[], int B[], int l, int r){
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

void quicksortName(string A[], int B[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartitionName(A, B, l, r);
        quicksortName(A, B, l, s - 1);
        quicksortName(A, B, s + 1, r);
    }
}

int HoarePartition(int A[], string B[], int l, int r){
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

void quicksort(int A[], string B[], int l, int r){
    int s;
    if(l < r){
        s = HoarePartition(A, B, l, r);
        quicksort(A, B, l, s - 1);
        quicksort(A, B, s + 1, r);
    }
}


int main(void){
    int numCases;
    string members[3];
    scanf("%d", &numCases);
    for(int z = 0; z < numCases; z++){
        int vertexCount = 0;
        int numTeams;
        scanf("%d", &numTeams);
        MatrixGraph myGraph(300);
        string Array[300];
        for(int j = 0; j < numTeams; j++){
            cin>>members[0]>>members[1]>>members[2];
            myGraph.setPos(members[0],members[1],members[2]);
        }
        myGraph.BFS(0);
        quicksort(myGraph.pathSizes, myGraph.membros, 0, (myGraph.usedVertex - 1));
        int i = 0;
        int k;
        while(i < myGraph.usedVertex - 1){
            k = i;
            while(myGraph.pathSizes[i] == myGraph.pathSizes[i+1])i++;
            quicksortName(myGraph.membros, myGraph.pathSizes, k, i);
            i++;
        }
        printf("%d\n", myGraph.usedVertex);
        for(int i = 0; i < myGraph.usedVertex; i++){
            cout<<myGraph.membros[i]<<" ";
            if(myGraph.pathSizes[i] == myGraph.usedVertex) cout<<"undefined"<<endl;
            else cout<<myGraph.pathSizes[i]<<endl;
        }
    }
    return 0;
}