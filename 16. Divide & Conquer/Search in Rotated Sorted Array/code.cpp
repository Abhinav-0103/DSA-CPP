#include<iostream>
#include<vector>
using namespace std;

int searchRotated(int arr[], int si, int ei, int target) {
    if(si > ei) {
        return -1;
    }

    int mid = (si + ei) / 2;

    if(arr[mid] == target) {
        return mid;
    } else if(arr[si] <= arr[mid]) {
        if((arr[si] <= target) && (target <= arr[mid])) {
            return searchRotated(arr,si,mid-1,target);
        } else {
            return searchRotated(arr,mid+1,ei,target);
        }
    } else {
        if((arr[mid] <= target) && (target <= arr[ei])) {
            return searchRotated(arr,mid+1,ei,target);
        } else {
            return searchRotated(arr,si,mid-1,target);
        }
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr) / sizeof(int);
    int target = 3;
    cout << "target index: " << searchRotated(arr,0,n-1,target) << endl;
}