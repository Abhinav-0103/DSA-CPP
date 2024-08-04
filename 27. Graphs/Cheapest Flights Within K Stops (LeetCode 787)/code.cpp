#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
    class Info {
        public :
            int u;
            int cost;
            int stops;

            Info(int u, int cost, int stops) {
                this->u = u;
                this->cost = cost;
                this->stops = stops;
            }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        q.push(Info(src,0,-1));

        while(!q.empty()) {
            Info curr = q.front();
            q.pop();

            for(int i=0;i<flights.size();i++) {
                if(flights[i][0] == curr.u) {
                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if(dist[v] > curr.cost + wt && curr.stops+1 <= k) {
                        dist[v] = curr.cost + wt;

                        q.push(Info(v,dist[v],curr.stops+1));
                    }
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    const int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, k = 1;

    Solution sol;

    cout << "Min Cost: " << sol.findCheapestPrice(n,flights,src,dst,k) << endl;
}