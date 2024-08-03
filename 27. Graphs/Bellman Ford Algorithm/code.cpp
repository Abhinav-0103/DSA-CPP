#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Edge {
    public :
        int v;
        int wt;

        Edge(int v, int wt) {
            this->v = v;
            this->wt = wt;
        }
};

void bellmanFordUtil(int src, int V, vector<vector<Edge>> graph, vector<int> &dist) {
    dist[src] = 0;

    for(int i=0;i<V-1;i++) {
        //Traverse All Edges
        for(int u=0;u<graph.size();u++) {
            vector<Edge> edges = graph[u];

            for(Edge edge: edges) {
                int v = edge.v;
                int wt = edge.wt;

                if(dist[v] > dist[u] + wt && dist[u] != INT_MAX) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
}

void bellmanFord(int src, vector<vector<Edge>> graph, int V) {
    vector<int> dist(V, INT_MAX);

    bellmanFordUtil(src,V,graph,dist);

    for(int i=0;i<dist.size();i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int V = 5;

    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,-4));

    graph[2].push_back(Edge(3,2));

    graph[3].push_back(Edge(4,4));

    graph[4].push_back(Edge(1,-1));

    bellmanFord(4,graph,V);
}