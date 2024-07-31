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

        bool hasPath(int src, int dest) {
            queue<int> q;
            vector<bool> vis(V, false);

            vis[src] = true;
            q.push(src);

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                if(u == dest) {
                    return true;
                }

                for(int v: l[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            return false;
        }
};

int main() {
    Graph graph(8);

    graph.add_edge(0,1);
    graph.add_edge(0,2);

    graph.add_edge(1,3);

    graph.add_edge(2,4);

    graph.add_edge(3,4);
    graph.add_edge(3,5);

    graph.add_edge(4,5);

    graph.add_edge(5,6);

    if(graph.hasPath(1,7)) {
        cout << "Path Exists" << endl;
    } else {
        cout << "Path does not Exist" << endl;
    }

    return 0;
}