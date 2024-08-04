#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

int main() {
    int n = 40;
    vector<int> dp(n+1,-1);

    dp[0] = 0;
    dp[1] = 1;

    cout << fib(n,dp) << endl;
}