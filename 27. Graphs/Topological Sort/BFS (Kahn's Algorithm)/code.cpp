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

        void calcInDeg(vector<int> &indeg) {
            for(int i=0;i<V;i++) {
                for(int v: l[i]) {
                    indeg[v]++;
                }
            }
        }

        void topSort() {
            vector<int> indeg(V,0);
            queue<int> q;

            calcInDeg(indeg);

            for(int i=0;i<indeg.size();i++) {
                if(indeg[i] == 0) {
                    q.push(i);
                }
            }

            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                cout << curr << " ";

                for(int v: l[curr]) {
                    indeg[v]--;

                    if(indeg[v] == 0) {
                        q.push(v);
                    }
                }
            }
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