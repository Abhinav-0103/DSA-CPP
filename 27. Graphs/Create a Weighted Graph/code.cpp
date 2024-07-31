#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<pair<int,int>>* l;

    public :
        Graph(int V) {
            this->V = V;
            l = new list<pair<int,int>>[V];
            // int* arr;
            // arr = new int[5]
        }

        void add_edge(int u, int v, int w) {
            l[u].push_back(make_pair(v, w));
            l[v].push_back(make_pair(u, w));
        }

        void print() {
            for(int i=0;i<V;i++) {
                cout << i << " -> ";
                for(pair<int,int> j: l[i]) {
                    cout << "(" << j.first << "," << j.second << ") ";
                }
                cout << endl;
            }
        }
};

int main() {
    Graph graph(5);

    graph.add_edge(0,1,5);
    graph.add_edge(1,2,1);
    graph.add_edge(1,3,3);
    graph.add_edge(2,3,1);
    graph.add_edge(2,4,2);

    graph.print();

    return 0;
}