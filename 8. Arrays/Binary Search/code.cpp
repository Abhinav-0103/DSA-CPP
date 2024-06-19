#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int mid;

    while(start <= end) {
        mid = (start + end) / 2;

        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter the key to be searched : ";
    cin >> key;

    int keyFound = binarySearch(arr, n, key);

    if(keyFound != -1) {
        cout << "The key was found at " << keyFound << " index" << endl;
    } else {
        cout << "The key was not found" << endl;
    }

    return 0;
}