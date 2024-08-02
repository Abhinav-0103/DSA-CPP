#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

    void topSort(int src, vector<bool> &vis, stack<int> &s, list<int> *l) {
        vis[src] = true;
        
        for(int v: l[src]) {
            if(!vis[v]) {
                topSort(v,vis,s,l);
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
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

        vector<int> ans;

        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(isCycle(i,vis,recPath,l)) {
                    return ans;
                }
            }
        }

        vector<bool> newVis(V, false);
        stack<int> s;

        for(int i=0;i<V;i++) {
            if(!newVis[i]) {
                topSort(i,newVis,s,l);
            }
        }

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> graph;

    vector<int> edge1 = {1,0};

    graph.push_back(edge1);

    Solution sol;

    vector<int> ans = sol.findOrder(numCourses,graph);

    for(int i: ans) {
        cout << i << " ";
    }
}