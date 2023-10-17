/*#include<iostream>
#include<list>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

class DS{
    vector<pair<int,int>> l;
public:

    DS(){
        vector<pair<int, int>> l;
    }

    void create_disjointSubset(int n){
      for(int i=0;i<n;i++){
        l.push_back({i,-1});
      }
    }

    int find(int curr){
        if(l[curr].second == -1){
            return curr;
        }
        l[curr].second = find(l[curr].second);
        return l[curr].second;
    }

    void unn(int a, int b){
      int root1, root2;
      root1 = find(a);
      root2 = find(b);

      if(root1 != root2){
        l[root2].second = root1;
      }
    }
    void printl(int n){
        cout<<"HEREEE";
        for(int i=0;i<n;i++){
				cout << l[i].first << " - " << l[i].second << ", ";
			}
            cout<<endl;
    }
};

class Graph{

	int *V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = new int(v);
		l = new list<pair<int,int> >[*V];
	}

	void addEdge(int u,int v,int wt,bool undir = false){
		l[u].push_back({v,wt});
		if(undir){
			l[v].push_back({u,wt});
		}
	}

    int size(){
        return (*V);
    }

  int next(int v, int w){
    int n = *V;
    int i = w + 1;

    for(const auto node : l[v]){
        if(node.first != 0 && node.first > w){
            return i;
        }
    }
    return n;
  }

  int first(int v){
    int n = *V;

    for(const auto node : l[v]){
        if(node.first != -1){
            return node.first;
        }
    }
    return n;
  }

  int weight(int p, int s){
    for(const auto node : l[p]){
            cout << " -- " << node.second << endl;
        if(node.first == s){
            return node.second;
        }
    }
    return 20000;
  }

  void printAdjList(){
		for(int i=0;i<(*V);i++){
			cout<< " ***** " <<i<<"-->";
			for(const auto node : l[i]){
				cout << node.first << " - " << node.second << ", ";
			}
			cout <<endl;
		}
	}
};

typedef struct{
    int i, w, wg;
} fla;

bool cmp(fla a, fla b) {
  if (a.wg >= b.wg)
    return true;
  return false;
}

void kruskal(Graph * g, Graph * F, DS * ds){
    g->printAdjList();
    int edgecnt = 1, w, v, u, wt;
    int n = g->size();
    fla aux;
    vector<fla> trash;

    for(int i=0;i<n-1;i++){
        w = g->first(i);
        while(w < n){
            aux.i = i; aux.w = w; aux.wg = g->weight(i,w); // fzr a função weight
            trash.push_back(aux);
            edgecnt++;
            w = g->next(i, w);
        }
    }

    sort(trash.begin(), trash.end(), cmp);
    ds->create_disjointSubset(n);
    while(n > 1 && trash.empty() == 0){
        aux = trash.back();
        cout << " empty >" << trash.empty() << endl;
        v = aux.i; u = aux.w; wt = aux.wg;
        trash.pop_back();

        if(ds->find(v) != ds->find(u)){
            ds->unn(v,u);
             cout << v << " " << u << " " << wt << endl;
            F->addEdge(v,u,wt);
            n--;
        }else{
           cout << " %% " << wt << endl;
        }
    }
    ds->printl(n);
    
    F->printAdjList();

}


int main(){
    DS ds;
    Graph g(3);
    Graph f(3);
	g.addEdge(0,1,1, true);
	g.addEdge(1,2,2, true);
	g.addEdge(2,0,3, true);
    kruskal(&g,&f,&ds);
}*/
/*
#include<iostream>
#include<list>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

class DS{
    vector<pair<int,int>> l;
public:

    DS(){
        vector<pair<int, int>> l;
    }

    void create_disjointSubset(int n){
      for(int i=0;i<n;i++){
        l.push_back({i,-1});
      }
    }

    int find(int curr){
        if(l[curr].second == -1){
            return curr;
        }
        l[curr].second = find(l[curr].second);
        return l[curr].second;
    }

    void unn(int a, int b){
      int root1, root2;
      root1 = find(a);
      root2 = find(b);

      if(root1 != root2){
        l[root2].second = root1;
      }
    }
    void printl(int n){
        cout<<"HEREEE";
        for(int i=0;i<n;i++){
				cout << l[i].first << " - " << l[i].second << ", ";
			}
            cout<<endl;
    }
};

class Graph{

	int *V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = new int(v);
		l = new list<pair<int,int> >[*V];
	}

	void addEdge(int u,int v,int wt,bool undir = false){
		l[u].push_back({v,wt});
		if(undir){
			l[v].push_back({u,wt});
		}
	}

    int size(){
        return (*V);
    }

  int next(int v, int w){
    int n = *V;
    int i = w + 1;

    for(const auto node : l[v]){
        if(node.first != 0 && node.first > w){
            return i;
        }
    }
    return n;
  }

  int first(int v){
    int n = *V;

    for(const auto node : l[v]){
        if(node.first != -1){
            return node.first;
        }
    }
    return n;
  }

  int weight(int p, int s){
    for(const auto node : l[p]){
            cout << " -- " << node.second << endl;
        if(node.first == s){
            return node.second;
        }
    }
    return 20000;
  }

  void printAdjList(){
		for(int i=0;i<(*V);i++){
			cout<< " ***** " <<i<<"-->";
			for(const auto node : l[i]){
				cout << node.first << " - " << node.second << ", ";
			}
			cout <<endl;
		}
	}
};

typedef struct{
    int i, w, wg;
} fla;

bool cmp(fla a, fla b) {
  if (a.wg >= b.wg)
    return true;
  return false;
}

void kruskal(Graph * g, Graph * F, DS * ds){
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
    ds->printl(n);
    
    F->printAdjList();

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
}
*/
