#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print(vector<vector<int>> dp) {
    for(vector<int> v: dp) {
        for(int i: v) {
            cout << i << "\t";
        }
        cout << endl;
    }
}

int lcs(string str1, string str2) {
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    int n = str1.size();
    int m = str2.size();

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    print(dp);

    return dp[n][m];
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";  

    int ans = lcs(str1,str2);

    cout << "Length: " << ans << endl;
}