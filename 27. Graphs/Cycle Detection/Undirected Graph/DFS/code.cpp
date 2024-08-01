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
            l[v].push_back(u);
        }

        bool detectCycleUtil(int src, int par, vector<bool> &vis) {
            vis[src] = true;

            for(int v: l[src]) {
                if(!vis[v]) {
                    if(detectCycleUtil(v, src, vis)) {
                        return true;
                    }
                } else if(v != par) {
                    return true;
                }
            }

            return false;
        }

        bool detectCycle() {
            vector<bool> vis(V, false);

            for(int i=0;i<V;i++) {
                if(!vis[i]) {
                    if(detectCycleUtil(i, -1, vis)) {
                        return true;
                    }
                }
            }

            return false;
        }
};

int main() {
    Graph graph(5);

    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(0,3);

    graph.add_edge(1,2);
    graph.add_edge(3,4);

    if(graph.detectCycle()) {
        cout << "Cycle Exists" << endl;
    } else {
        cout << "Cycle does not exist" << endl;
    }

    return 0;
}