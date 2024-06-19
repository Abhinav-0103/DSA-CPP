#include<iostream>
using namespace std;

int getNextRow(int row, int col, int idx, int n) {
    if(col == n-1) {
        if(row != n-1){
            return row + 1 + idx;
        } else {
            return row + idx;
        }
    } else if(col == 0) {
        if(row != 0) {
            return row - 1 + idx;
        } else {
            return row + idx;
        }
    } else if(row == 0 || row == n-1) {
        return row + idx;
    } else {
        return - 1;
    }
}

int getNextCol(int row, int col, int idx, int n) {
    if(row == n-1) {
        if(col != 0){
            return col - 1 + idx;
        } else {
            return col + idx;
        }
    } else if(row == 0) {
        if(col != n-1) {
            return col + 1 + idx;
        } else {
            return col + idx;
        }
    } else if(col == 0 || col == n-1) {
        return col + idx;
    } else {
        return -1;
    }
}

void printArray(int arr[][4], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void rotateImg(int arr[][4], int n) {
    int curr_size = n;
    for(int i=0;i<n/2;i++) {
        int count = curr_size - 1;
        int row = i, col = i;
        int val = arr[i][i], curr = arr[i][i];
        while(count--) {
            do {
                int nrow = getNextRow(row-i,col-i,i,curr_size);
                int ncol = getNextCol(row-i,col-i,i,curr_size);

                int temp = arr[nrow][ncol];
                arr[nrow][ncol] = curr;
                curr = temp;

                row = nrow;
                col = ncol;
            }while(row!=i || col!=i);

            int nrow = getNextRow(row,col,i,n);
            int ncol = getNextCol(row,col,i,n);

            int temp = arr[nrow][ncol];
            arr[nrow][ncol] = curr;
            curr = temp;
        }

        curr_size = n - 2;
    }
}


int main() {
    int arr[][4] = {{5,1,9,11},
                    {2,4,8,10},
                    {13,3,6,7},
                    {15,14,12,16}};

    int arr2[][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    
    int n = 4;

    printArray(arr,n);
    rotateImg(arr,n);

    cout << endl << endl;

    printArray(arr,n);

}