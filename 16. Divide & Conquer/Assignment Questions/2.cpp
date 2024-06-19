#include<iostream>
using namespace std;

int countInRange(int arr[], int left, int right, int num) {
    int count = 0;

    for(int i=left;i<=right;i++) {
        if(arr[i] == num) {
            count++;
        }
    }

    return count;
}

int majorityElementUtil(int arr[], int si, int ei) {
    if(si == ei) {
        return arr[si];
    }

    int mid = (si + ei) / 2;

    int leftMajorityElement = majorityElementUtil(arr,si,mid);
    int rightMajorityElement = majorityElementUtil(arr,mid+1,ei);

    if(leftMajorityElement == rightMajorityElement) {
        return leftMajorityElement;
    }

    int leftMajorCount = countInRange(arr,si,mid,leftMajorityElement);
    int rightMajorCount = countInRange(arr,si,mid,rightMajorityElement);

    return leftMajorCount > rightMajorCount ? leftMajorityElement : rightMajorityElement;
}

int majorityElement(int arr[], int n) {
    return majorityElementUtil(arr,0,n-1);
}

int main() {
    int arr[] = {3, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    int majorEl = majorityElement(arr,n);

    cout << "The Majority Element = " << majorEl << endl;
}