#include<iostream>
using namespace std;

void printArray(int arr[][100], int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print2D(int arr[], int size, int m, int n) {
    if(size == m * n) {
        int arr2D[100][100] = {0};
        int counter = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                arr2D[i][j] = arr[counter++];
            }
        }

        printArray(arr2D,m,n);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(int);

    int n = 3;
    int m = 2;

    print2D(arr, size, m, n);
}