#include<iostream>
#include<vector>
using namespace std;

int countWays(int n, vector<int> &dp) {
    for(int i=3;i<n+1;i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main() {
    int n = 10;
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    cout << countWays(n, dp) << endl;
}