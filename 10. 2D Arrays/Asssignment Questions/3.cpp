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

void printTrans(int arr[][3], int n, int m) {
    int arrT[100][100] = {0};

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            arrT[j][i] = arr[i][j];
        }
    }

    printArray(arrT,m,n);
}

int main() {
    int arr[][3] = {{4,7,8},
                    {8,8,7}};
    int n = 2, m = 3;

    printTrans(arr,n,m);

    return 0;
}