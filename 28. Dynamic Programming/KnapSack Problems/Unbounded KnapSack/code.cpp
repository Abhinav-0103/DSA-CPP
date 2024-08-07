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

int knapSack(int n, int W, vector<int> val, vector<int> wt) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=W;j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j) {
                int include = dp[i][j-itemWt] + itemVal;
                int exclude = dp[i-1][j];

                dp[i][j] = max(include, exclude);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    print(dp);

    return dp[n][W];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int W = 7;
    int n = val.size();

    int ans = knapSack(n,W,val,wt);

    cout << "Max Profit: " << ans << endl;

    return 0;
}