#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int lis(vector<int> arr) {
    unordered_set<int> s(arr.begin(), arr.end());

    int n1 = arr.size();

    vector<int> unqArr(s.begin(), s.end());

    sort(unqArr.begin(), unqArr.end());

    int n2 = unqArr.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            if(arr[i-1] == unqArr[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n1][n2];
}

int main() {
    vector<int> arr = {50, 3, 10, 7, 40, 80};

    int lisLen = lis(arr);

    cout << "LIS Length: " << lisLen << endl;
}