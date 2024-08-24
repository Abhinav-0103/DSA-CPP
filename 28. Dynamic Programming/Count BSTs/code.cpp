#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        int i,j;
        for(i=2;i<=n;i++) {
            for(j=0;j<i;j++) {
                dp[i] += (dp[j] * dp[i-j-1]);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Count for " << n << ": " << sol.numTrees(n) << endl;
}