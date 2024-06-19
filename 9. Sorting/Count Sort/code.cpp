#include<iostream>
#include<climits>
using namespace std;

void countSort(int arr[], int n) {
    int freq[10000];
    int minVal = INT_MAX, maxVal = INT_MIN;

    for(int i=0;i<n;i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    // O(n)
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
    }

    // O(range)
    for(int i=minVal,j=0;i<=maxVal;i++) {
        while(freq[i] > 0) {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);
    countSort(arr, n);
    printArray(arr, n);
}