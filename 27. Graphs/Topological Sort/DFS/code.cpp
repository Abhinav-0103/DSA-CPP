#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

        void topSortUtil(int src, vector<bool> &vis, stack<int> &s) {
            vis[src] = true;

            for(int v: l[src]) {
                if(!vis[v]) {
                    topSortUtil(v,vis,s);
                }
            }

            s.push(src);
        }

        void topSort() {
            vector<bool> vis(V,false);
            stack<int> s;

            for(int i=0;i<V;i++) {
                if(!vis[i]) {
                    topSortUtil(i,vis,s);
                }
            }

            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }

            cout << endl;
        }
};

int main() {
    Graph graph(6);

    graph.add_edge(2,3);
    graph.add_edge(3,1);
    graph.add_edge(4,0);
    graph.add_edge(4,1);
    graph.add_edge(5,0);
    graph.add_edge(5,2);

    graph.topSort();

    return 0;
}