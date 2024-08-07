#include<iostream>
#include<vector>
using namespace std;

int knapSack(int n, int W, vector<int> val, vector<int> wt, vector<vector<int>> &dp) {
    if(n == 0 || W == 0) {
        return 0;
    }

    if(dp[n][W] != -1) {
        cout << n << ", " << W << endl;
        return dp[n][W];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W) {
        int include = knapSack(n-1, W-itemWt, val, wt, dp) + itemVal;
        int exclude = knapSack(n-1, W, val, wt, dp);

        dp[n][W] = max(include, exclude);
    } else {
        dp[n][W] = knapSack(n-1, W, val, wt, dp);
    }

    return dp[n][W];
}

void print(vector<vector<int>> dp) {
    for(vector<int> v: dp) {
        for(int i: v) {
            cout << i << "\t";
        }

        cout << endl;
    }
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