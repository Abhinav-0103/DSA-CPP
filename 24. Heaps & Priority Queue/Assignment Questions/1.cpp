#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i: stones) {
            pq.push(i);
        }

        if(pq.size() == 1) {
            return pq.top();
        }

        int i,j;

        while(pq.size() > 1) {
            i = pq.top();
            pq.pop();
            j = pq.top();
            pq.pop();

            if(i == j) {
                continue;
            } else {
                i = i - j;

                pq.push(i);
            }
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2,7,4,1,8,1};

    int ans = sol.lastStoneWeight(arr);

    cout << "Answer: " << ans << endl;
}