#include<iostream>
using namespace std;

void insertionSort(char arr[], int n) {
    for(int i=1;i<n;i++) {
        int curr = arr[i];
        int prev = i - 1;

        while(prev>=0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }

        arr[prev + 1] = curr; // Not Required
    }
}

void printArray(char arr[], int n) {
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main() {
    char arr[] = {'f', 'b', 'a', 'e', 'c', 'd'};
    int n = sizeof(arr) / sizeof(char);

    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
}