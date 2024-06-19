#include<iostream>
using namespace std;

bool search(int mat[][4], int n, int m, int key) {
    for(int i=0;i<n;i++) {
        int start = 0;
        int end = m - 1;
        int mid = (start + end) / 2;
        while(start <= end) {
            if(mat[i][mid] == key) {
                cout << "Found " << key << " at (" << i << "," << mid << ")" << endl;
                return true;
            } else if(mat[i][mid] > key) {
                end = m - 1;
            } else {
                start = m + 1;
            }
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

    search(matrix,n,m,key);

    return 0;
}