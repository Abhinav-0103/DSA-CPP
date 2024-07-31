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

        void dfsUtil(int u, vector<bool> &vis) {
            vis[u] = true;
            cout << u << " ";

            for(int v: l[u]) {
                if(!vis[v]) {
                    dfsUtil(v, vis);
                }
            }
        }

        void dfs() {
            int u = 0;
            vector<bool> vis(V, false);

            dfsUtil(u, vis);
        }
};

int main() {
    Graph graph(7);

    graph.add_edge(0,1);
    graph.add_edge(0,2);

    graph.add_edge(1,3);

    graph.add_edge(2,4);

    graph.add_edge(3,4);
    graph.add_edge(3,5);

    graph.add_edge(4,5);

    graph.add_edge(5,6);

    graph.dfs();

    return 0;
}