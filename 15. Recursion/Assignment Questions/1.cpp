#include<iostream>
#include<vector>
using namespace std;

bool binSearchUtil(vector<int> arr, int start, int end, int key) {
    if(start > end) {
        return false;
    }

    int mid = (start + end) / 2;

    if(arr[mid] == key) {
        return true;
    } else if(arr[mid] > key) {
        return binSearchUtil(arr,start,mid-1,key);
    }

    return binSearchUtil(arr,mid+1,end,key);
}

bool binarySearch(vector<int> arr, int key) {
    return binSearchUtil(arr,0,arr.size()-1,key);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int key = 2;

    if(binarySearch(arr,key)) {
        cout << "Key Found" << endl;
    } else {
        cout << "Key Not Found" << endl;
    }
    return 0;
}