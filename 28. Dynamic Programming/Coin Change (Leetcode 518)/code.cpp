#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for(int i=0;i<=n;i++) {
            dp[i][0] = 1;
        }

        int incl;
        int excl;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amount;j++) {
                if(coins[i-1] <= j) {
                    incl = dp[i][j-coins[i-1]];
                    excl = dp[i-1][j];

                    dp[i][j] = incl + excl;   
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount];
    }
};

int main() {
    int amount = 5;
    vector<int> coins = {1,2,5};

    Solution sol;
    int ways = sol.change(amount, coins);

    cout << "Ways = " << ways << endl;
}