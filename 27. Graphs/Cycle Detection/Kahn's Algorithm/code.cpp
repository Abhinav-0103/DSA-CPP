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

        bool hasCycle() {
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

                for(int v: l[curr]) {
                    indeg[v]--;

                    if(indeg[v] == 0) {
                        q.push(v);
                    }
                }
            }

            for(int i: indeg) {
                if(i != 0) {
                    return true;
                }
            }

            return false;
        }
};

int main() {
    Graph graph(4);

    graph.add_edge(0,2);
    graph.add_edge(1,2);
    graph.add_edge(2,3);
    graph.add_edge(3,1);

    if(graph.hasCycle()) {
        cout << "Cycle Found" << endl;
    } else {
        cout << "Cycle Not Found" << endl;
    }

    return 0;
}