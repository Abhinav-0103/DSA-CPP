#include<iostream>
#include<vector>
using namespace std;

int catalan(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int sum = 0;

    for(int i=0;i<n;i++) {
        sum += (catalan(i,dp) * catalan(n-i-1,dp));
    }

    return dp[n] = sum;
}

int main() {
    int n = 25;
    vector<int> dp(n+1, -1);

    int ans = catalan(n,dp);

    cout << n << "th Catalan: " << ans << endl;
}