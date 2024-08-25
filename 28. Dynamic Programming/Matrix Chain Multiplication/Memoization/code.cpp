#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mcm(vector<int> arr, int i, int j, vector<vector<int>> &dp) {
    if(i == j) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k=i;k<j;k++) {
        int cost1 = mcm(arr,i,k,dp);
        int cost2 = mcm(arr,k+1,j,dp);

        int total = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);

        ans = min(ans, total);
    }

    return dp[i][j] = ans;
}

int main() {
    vector<int> arr = {1,2,3,4,3};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n,-1));

    int minCost = mcm(arr,1,n-1,dp);

    cout << "Min Cost: " << minCost << endl;
}