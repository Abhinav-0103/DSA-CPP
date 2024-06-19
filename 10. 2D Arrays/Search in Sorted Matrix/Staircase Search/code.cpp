#include<iostream>
using namespace std;

bool search1(int mat[][4], int n, int m, int key) {
    // Starting from top right corner
    int row = 0;
    int col = m - 1;

    while((row < n) && (col >= 0)) {
        if(mat[row][col] == key) {
            cout << "Found " << key << " at (" << row << "," << col << ")" << endl;
            return true;
        } else if(mat[row][col] < key) {
            row++;
        } else {
            col--;
        }
    }

    return false;
}

bool search2(int mat[][4], int n, int m, int key) {
    // Starting from bottom left corner
    int row = n - 1;
    int col = 0;

    while((row >= 0) && (col < m)) {
        if(mat[row][col] == key) {
            cout << "Found " << key << " at (" << row << "," << col << ")" << endl;
            return true;
        } else if(mat[row][col] < key) {
            col++;
        } else {
            row--;
        }
    }

    return false;
}

int main() {
    int matrix[4][4] = {{10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,48},
                        {32,33,39,50}};
    
    int n = 4, m = 4;
    
    int key = 33;

    search1(matrix,n,m,key);
    search2(matrix,n,m,key);

    return 0;
}