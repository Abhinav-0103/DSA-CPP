#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr) / sizeof(int);

    cout << "Initial Array : ";
    printArray(arr, n);
    cout << "Ascending Array : ";
    sort(arr, arr + n);
    printArray(arr, n);
    cout << "Descending Array : ";
    sort(arr, arr + n, greater<int>());
    printArray(arr, n);
}