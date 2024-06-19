#include<iostream>
#include<vector>
using namespace std;

int partition(int arr[], int si, int ei) {
    int i = si - 1;
    int pivot = arr[ei];
    for(int j=si;j<ei;j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    i++;
    swap(arr[i],arr[ei]);

    return i;
}

void quickSortAscending(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }

    int pivotIdx = partition(arr,si,ei);

    quickSortAscending(arr,si,pivotIdx-1);
    quickSortAscending(arr,pivotIdx+1,ei);
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[] = {6,3,7,5,4,2};
    int n = sizeof(arr) / sizeof(int);
    cout << "Size: " << n << endl;
    cout << "Before Sorting:" << endl;
    printArray(arr,n);
    quickSortAscending(arr,0,n-1);
    cout << "After Sorting:" << endl;
    printArray(arr,n);
}