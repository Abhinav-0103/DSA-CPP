#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<string>
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

        void allPathsUtil(int src, int dest, vector<bool> &vis, string &path) {
            if(src == dest) {
                cout << path << dest << endl;
                return;
            }

            vis[src] = true;
            path.push_back(to_string(src)[0]);

            for(int v: l[src]) {
                if(!vis[v]) {
                    allPathsUtil(v,dest,vis,path);
                }
            }

            path.pop_back();
            vis[src] = false;
        }

        void allPaths(int src, int dest) {
            vector<bool> vis(V, false);
            string path = "";
            allPathsUtil(src,dest,vis,path);
        }
};

int main() {
    Graph graph(6);

    graph.add_edge(0,3);

    graph.add_edge(2,3);

    graph.add_edge(3,1);

    graph.add_edge(4,0);
    graph.add_edge(4,1);

    graph.add_edge(5,0);
    graph.add_edge(5,2);


    graph.allPaths(5,1);

    return 0;
}