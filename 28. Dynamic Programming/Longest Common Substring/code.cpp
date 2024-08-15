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

int longestCommonSubstring(string str1, string str2) {
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    int n = str1.size();
    int m = str2.size();

    int ans = 0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    print(dp);

    return ans;
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";  

    int ans = longestCommonSubstring(str1,str2);

    cout << "Length: " << ans << endl;
}