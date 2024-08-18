#include<iostream>
#include<vector>
using namespace std;

int catalan(int n) {
    vector<int> dp(n+1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++) {
        int ans = 0;
        for(int j=0;j<i;j++) {
            ans += (dp[j] * dp[i-j-1]);
        }

        dp[i] = ans;
    }

    for(int i: dp) {
        cout << i << " ";
    }
    cout << endl;

    return dp[n];
}

int main() {
    int n = 6;

    int ans = catalan(n);

    cout << n << "th Catalan: " << ans << endl;
}