#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcs(string str1, int n, string str2, int m, string &ans) {
    if(n == 0 || m == 0) {
        return 0;
    }

    if(str1[n-1] == str2[m-1]) {
        string temp(1,str1[n-1]);
        ans = temp + ans;
        return lcs(str1,n-1,str2,m-1,ans) + 1;
    } else {
        int reduceStr1 = lcs(str1,n-1,str2,m,ans);
        int reduceStr2 = lcs(str1,n,str2,m-1,ans);

        return max(reduceStr1, reduceStr2);
    }
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";  
    string ansLcs = "";

    int ans = lcs(str1,str1.length(),str2,str2.length(),ansLcs);

    cout << "LCS: " << ansLcs << "; Length: " << ans << endl;
}