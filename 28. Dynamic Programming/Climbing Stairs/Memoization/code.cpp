#include<iostream>
#include<vector>
using namespace std;

int countWays(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = countWays(n-1,dp) + countWays(n-2,dp);
}

int main() {
    int n = 39;
    vector<int> dp(n+1,-1);

    cout << countWays(n, dp) << endl;
}