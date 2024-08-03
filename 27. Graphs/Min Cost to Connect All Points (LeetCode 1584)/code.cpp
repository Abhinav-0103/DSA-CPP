#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int dist(vector<int> p1, vector<int> p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> mstSet(points.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0,0));
        int ans = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            vector<int> point = points[u];
            int cost = pq.top().first;

            pq.pop();

            if(!mstSet[u]) {
                mstSet[u] = true;
                ans += cost;

                for(int i=0;i<points.size();i++) {
                    if(i != u) {
                        int wt = dist(points[i], points[u]);

                        pq.push(make_pair(wt,i));
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

    cout << "Min Cost: " << sol.minCostConnectPoints(points) << endl;
}