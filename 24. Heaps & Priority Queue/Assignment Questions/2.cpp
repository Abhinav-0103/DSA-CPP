#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i: nums) {
            pq.push(i);
        }

        int ans;

        while(k--) {
            ans = pq.top();
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2,7,4,1,8,1};

    int ans = sol.findKthLargest(arr, 3);

    cout << "Answer: " << ans << endl;
}