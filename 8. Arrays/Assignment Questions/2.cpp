#include<iostream>
using namespace std;

int keyInSortedRotated(int arr[], int n, int target) {
    int start = 0, end = n-1;
    int mid;
    while(start <= end) {
        mid = (start + end) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[start] <= arr[end]) {
            if(arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if(arr[mid] > target) {
                if(arr[start] >= target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if(arr[end] < target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    int nums[] = {4,5,6,7,0,1,2};
    int n = sizeof(nums) / sizeof(int);
    int target;
    cout << "Enter the target value : ";
    cin >> target;
    cout << "The target = " << target << " is present at index : " << keyInSortedRotated(nums, n, target) << endl;
}