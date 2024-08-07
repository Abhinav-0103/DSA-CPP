#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> dp) {
    for(vector<int> v: dp) {
        for(int i: v) {
            cout << i << "\t";
        }

        cout << endl;
    }
}

int knapSack(int n, int W, vector<int> val, vector<int> wt, vector<vector<int>> &dp) {
    for(int i=0;i<=n;i++) {
        dp[i][0] = 0;
    }

    for(int i=0;i<=W;i++) {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=W;j++) {
            if(wt[i-1] <= j) {
                int itemIdx = i - 1;
                int include = dp[i-1][j-wt[itemIdx]] + val[itemIdx];
                int exclude = dp[i-1][j];

                dp[i][j] = max(include, exclude);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int W = 7;
    int n = val.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    int ans = knapSack(n,W,val,wt,dp);

    cout << "Max Profit: " << ans << endl;

    print(dp);

    return 0;
}