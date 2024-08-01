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

        bool isBipartiteUtil(int src, vector<bool> &vis, vector<int> &col) {
            queue<int> q;

            vis[src] = true;
            col[src] = 0;
            q.push(src);

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v: l[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        col[v] = !col[u];

                        q.push(v);
                    } else if(col[v] == col[u]) {
                        return false;
                    }
                }
            }

            return true;
        }

        bool isBipartite() {
            vector<bool> vis(V, false);
            vector<int> col(V, -1);

            for(int i=0;i<V;i++) {
                if(!vis[i]) {
                    if(isBipartiteUtil(i, vis, col)) {
                        return true;
                    }
                }
            }

            return false;
        }
};

int main() {
    Graph graph(4);

    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,3);
    graph.add_edge(2,3);

    if(graph.isBipartite()) {
        cout << "Bipartite Graph" << endl;
    } else {
        cout << "Not a Bipartite Graph" << endl;
    }

    return 0;
}