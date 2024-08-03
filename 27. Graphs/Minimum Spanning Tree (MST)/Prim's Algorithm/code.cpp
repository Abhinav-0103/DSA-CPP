#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* l;

    public :
        Graph(int V) {
            this->V = V;
            l = new list<pair<int, int>>[V];
            // int* arr;
            // arr = new int[5]
        }

        void add_edge(int u, int v, int wt) {
            l[u].push_back(make_pair(wt,v));
            l[v].push_back(make_pair(wt,u));
        }

        int prims() {
            vector<bool> mstSet(V,false);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            pq.push(make_pair(0,0));
            int ans = 0;

            while(!pq.empty()) {
                int u = pq.top().second;
                int cost = pq.top().first;

                pq.pop();

                if(!mstSet[u]) {
                    mstSet[u] = true;
                    ans+=cost;

                    for(pair<int,int> edge: l[u]) {
                        pq.push(edge);
                    }
                }
            }

            return ans;
        }
};

int main() {
    Graph graph(5);

    graph.add_edge(0,1,10);
    graph.add_edge(0,2,15);
    graph.add_edge(0,3,30);
    graph.add_edge(1,3,40);
    graph.add_edge(2,3,50);

    int minCost = graph.prims();

    cout << "Min Cost: " << minCost << endl;

    return 0;
}