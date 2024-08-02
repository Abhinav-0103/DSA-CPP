#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, list<int>* l) {
        vis[src] = true;
        recPath[src] = true;

        for(int v: l[src]) {
            if(!vis[v]) {
                if(isCycle(v,vis,recPath,l)) {
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        list<int> *l;
        l = new list<int>[V];

        for(int i=0;i<graph.size();i++) {
            int u = graph[i][1];
            int v = graph[i][0];

            l[u].push_back(v);
        }

        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(isCycle(i,vis,recPath,l)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> graph;

    vector<int> edge1 = {0,1};
    vector<int> edge2 = {1,0};

    graph.push_back(edge1);
    graph.push_back(edge2);

    Solution sol;

    cout << sol.canFinish(numCourses,graph) << endl;
}