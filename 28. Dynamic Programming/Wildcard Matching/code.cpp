#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<bool>> dp) {
    for(vector<bool> v: dp) {
        for(int i: v) {
            cout << i << "\t";
        }
        cout << endl;
    }
}

bool wildcardMatch(string t, string p) {
    int n = t.size();
    int m = p.size();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;

    for(int i=1;i<=m;i++) {
        if(p[i-1] == '*') {
            dp[0][i] = dp[0][i-1];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(t[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    print(dp);

    return dp[n][m];
}

int main() {
    string t = "aaabab";
    string p = "a*ab";

    bool isPos = wildcardMatch(t,p);

    if(isPos) {
        cout << "Match is Possible" << endl;
    } else {
        cout << "Match is not Possible" << endl;
    }
}