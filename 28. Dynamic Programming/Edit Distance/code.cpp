#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> dp) {
    for(vector<int> v: dp) {
        for(int i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int editDist(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++) {
        dp[i][0] = i;
    }

    for(int i=1;i<=m;i++) {
        dp[0][i] = i;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                int insert = dp[i][j-1];
                int del = dp[i-1][j];
                int replace = dp[i-1][j-1];

                dp[i][j] = 1 + min(insert, min(del, replace));
            }
        }
    }

    print(dp);

    return dp[n][m];
}

int main() {
    string str1 = "horse";
    string str2 = "ros";

    int minOps = editDist(str1, str2);

    cout << "Minimum Operations: " << minOps << endl;
}