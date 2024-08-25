#include<iostream>
#include<vector>
using namespace std;

int minPart(vector<int> nums) {
    int totSum = 0;
    for(int i: nums) {
        totSum += i;
    }

    int n = nums.size();
    int W = totSum / 2;

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=W;j++) {
            if(nums[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j-nums[i-1]] + nums[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int sum1 = dp[n][W];
    int sum2 = totSum - sum1;

    return abs(sum1 - sum2);
}

int main() {
    vector<int> nums = {1,6,11,5};

    int minDiff = minPart(nums);

    cout << "Min Diff: " << minDiff << endl;
}