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

int lcs(string str1, string str2, vector<vector<int>> &dp) {
    int n = str1.size();
    int m = str2.size();

    if(n == 0 || m == 0) {
        return 0;
    }

    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1]) {
        dp[n][m] = lcs(str1.substr(0,n-1),str2.substr(0,m-1),dp) + 1;
    } else {
        int reduceStr1 = lcs(str1.substr(0,n-1),str2,dp) ;
        int reduceStr2 = lcs(str1,str2.substr(0,m-1),dp) ;

        dp[n][m] = max(reduceStr1, reduceStr2);
    }

    return dp[n][m];
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";  

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, -1));

    int ans = lcs(str1,str2,dp);

    cout << "Length: " << ans << endl;

    print(dp);
}