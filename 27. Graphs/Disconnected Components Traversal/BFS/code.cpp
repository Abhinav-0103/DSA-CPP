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

        void bfsUtil(int n, vector<bool> &vis) {
            queue<int> q;

            vis[n] = true;
            q.push(n);

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                cout << u << " ";

                for(int v: l[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        void bfs() {
            vector<bool> vis(V, false);

            for(int i=0;i<V;i++) {
                if(!vis[i]) {
                    bfsUtil(i,vis);
                }
            }
        }
};

int main() {
    Graph graph(10);

    graph.add_edge(0,2);
    graph.add_edge(2,5);

    graph.add_edge(1,6);
    graph.add_edge(6,4);
    graph.add_edge(4,3);
    graph.add_edge(4,9);
    graph.add_edge(3,8);
    graph.add_edge(3,7);

    graph.bfs();

    return 0;
}