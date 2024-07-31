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

        bool hasPathUtil(int src, int dest, vector<bool> &vis) {
            if(src == dest) {
                return true;
            }

            vis[src] = true;

            for(int v: l[src]) {
                if(!vis[v]) {
                    if(hasPathUtil(v, dest, vis)) {
                        return true;
                    }
                }
            }

            return false;
        }

        bool hasPath(int src, int dest) {
            vector<bool> vis(V, false);

            return hasPathUtil(src, dest, vis);
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

    if(graph.hasPath(0,5)) {
        cout << "Path Exists" << endl;
    } else {
        cout << "Path does not Exist" << endl;
    }

    return 0;
}