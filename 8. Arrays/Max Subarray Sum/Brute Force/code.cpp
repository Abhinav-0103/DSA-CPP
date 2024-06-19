#include<iostream>
#include<climits>
using namespace std; 

int maxSubarraySum(int arr[], int n) {
    int maxSum = INT_MIN;
    for(int start=0;start<n;start++) {
        for(int end=start;end<n;end++) {
            int currSum = 0;
            for(int i=start;i<=end;i++) {
                currSum+=arr[i];
            }

            maxSum = max(currSum, maxSum);
        }
    }

    return maxSum;
}

int main() {
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = 6;

    int maxSum = maxSubarraySum(arr, n);

    cout << "Max Subarry Sum = " << maxSum<<endl; 
}