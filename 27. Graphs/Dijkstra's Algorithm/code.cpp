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

void dijkstraAlgoUtil(int src, int V, vector<vector<Edge>> graph, vector<int> &dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // priority_queue<int, vector<int>, greater<int> pq; -> For Min Heap
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;

        pq.pop();

        for(int i=0;i<graph[u].size();i++) {
            int v = graph[u][i].v;
            int wt = graph[u][i].wt;
            if(dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void dijkstraAlgo(int src, vector<vector<Edge>> graph, int V) {
    vector<int> dist(V, INT_MAX);

    dijkstraAlgoUtil(src,V,graph,dist);

    for(int i=0;i<dist.size();i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int V = 6;

    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkstraAlgo(0,graph,V);
}