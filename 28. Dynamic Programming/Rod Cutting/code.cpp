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

int rodCut(int n, int rodLength, vector<int> price, vector<int> length) {
    vector<vector<int>> dp(n+1, vector<int>(rodLength+1, 0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=rodLength;j++) {
            if(length[i-1] <= j) {
                dp[i][j] = max(dp[i][j-length[i-1]] + price[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][rodLength];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};

    int rodLength = 8;
    int n = length.size();

    int ans = rodCut(n,rodLength,price,length);

    cout << "Max Profit: " << ans << endl;

    return 0;
}