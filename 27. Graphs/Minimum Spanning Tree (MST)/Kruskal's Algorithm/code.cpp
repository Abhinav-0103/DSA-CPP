#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
    public :
        int u;
        int v;
        int wt;

        Edge(int u, int v, int wt) {
            this->u = u;
            this->v = v;
            this->wt = wt;
        }
};

class Graph {
    public :
        vector<Edge> edges;
        int V;
        vector<int> par;
        vector<int> rank;

        Graph(int V) {
            this->V = V;

            for(int i=0;i<V;i++) {
                par.push_back(i);
                rank.push_back(0);
            }
        }

        void addEdge(int u, int v, int wt) {
            edges.push_back(Edge(u,v,wt));
        }

        int find(int x) {
            if(par[x] == x) {
                return x;
            }

            return par[x] = find(par[x]);
        }

        void unionByRank(int a, int b) {
            int parA = find(a);
            int parB = find(b);

            if(rank[parA] == rank[parB]) {
                par[parB] = parA;
                rank[parA]++;
            } else if(rank[parA] < rank[parB]) {
                par[parA] = parB;
            } else {
                par[parB] = parA;
            }
        }

        void kruskalsAlgo() {
            sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});

            int ans = 0;
            int count = 0;

            for(int i=0;i<edges.size();i++) {
                Edge curr = edges[i];

                int parU = find(curr.u);
                int parV = find(curr.v);

                if(parU != parV ) {
                    unionByRank(curr.u, curr.v);
                    ans += curr.wt;
                    count++;
                }

                if(count == V-1) {
                    break;
                }
            }

            cout << "Min Weight: " << ans << endl;
        }
};

int main() {
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);

    graph.kruskalsAlgo();
    return 0;
}
