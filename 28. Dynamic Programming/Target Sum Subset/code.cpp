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

bool targetSum(vector<int> nums, int target) {
    int n = nums.size();

    vector<vector<int>> dp(n+1, vector<int>(target+1,0));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=target;j++) {
            int num = nums[i-1];

            if(num <= j) {
                int include = dp[i-1][j-num] + num;
                int exclude = dp[i-1][j];

                dp[i][j] = max(include, exclude);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    print(dp);

    if(dp[n][target] == target) {
        return true;
    }


    return false;
}

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 7;

    bool isPos = targetSum(nums, target);

    if(isPos) {
        cout << "Subset is possible" << endl;
    } else {
        cout << "Subset is not possible" << endl;
    }

    return 0;
}