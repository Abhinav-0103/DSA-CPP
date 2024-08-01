#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;

    public :
        Graph(int V) {
            this->V = V;
            l = new list<int> [V];
        }

        void add_edge(int u, int v) {
            l[u].push_back(v);
        }

        bool detectCycleUtil(int src, vector<bool> vis, vector<bool> recPath) {
            vis[src] = true;
            recPath[src] = true;

            for(int v: l[src]) {
                if(!vis[v]) {
                    if(detectCycleUtil(v,vis,recPath)) {
                        return true;
                    }
                } else if(recPath[v]) {
                    return true;
                }
            }

            return false;
        }

        bool detectCycle() {
            vector<bool> vis(V, false);
            vector<bool> recPath(V, false);

            for(int i=0;i<V;i++) {
                if(!vis[i]) {
                    if(detectCycleUtil(i,vis,recPath)) {
                        return true;
                    }
                }
            }

            return false;
        }
};

int main() {
    Graph graph(4);

    graph.add_edge(1,0);

    graph.add_edge(0,2);
    graph.add_edge(2,3);
    graph.add_edge(3,0);

    if(graph.detectCycle()) {
        cout << "Cycle Exists" << endl;
    } else {
        cout << "Cycle does not exist" << endl;
    }

    return 0;
}