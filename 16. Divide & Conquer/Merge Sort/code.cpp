#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int ei, int mid) {
    vector<int> temp;

    int i = si;
    int j = mid + 1;

    while((i <= mid) && (j <= ei)) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=si, x=0;idx<=ei;idx++) {
        arr[idx] = temp[x];
        x++;
    }
}

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }

    int mid = (si + ei) / 2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);

    merge(arr,si,ei,mid);
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
    mergeSort(arr,0,n-1);
    cout << "After Sorting:" << endl;
    printArray(arr,n);
}