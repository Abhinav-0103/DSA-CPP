#include<iostream>
using namespace std;

void spiralMatrix(int matrix[][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;

    while((srow <= erow) && (scol <= ecol)) {
        //Top
        for(int j=scol;j<=ecol;j++) {
            cout << matrix[srow][j] << " ";
        }
        //Right
        for(int i=srow+1;i<=erow;i++) {
            cout << matrix[i][ecol] << " ";
        }
        //Bottom
        for(int j=ecol-1;j>=scol;j--) {
            if(srow == erow) {
                break;
            }
            cout << matrix[erow][j] << " ";
        }  
        //Left
        for(int i=erow-1;i>=srow+1;i--) {
            if(ecol == scol) {
                break;
            }

            cout << matrix[i][scol] << " ";
        }

        srow++;
        scol++;
        erow--;
        ecol--;
    }
}

int main() {
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};

    int matrix3d[3][3] = {{1,2,3},
                        {5,6,7},
                        {9,10,11}};
    
    int n = 4, m = 4;
    spiralMatrix(matrix,n,m);

    return 0;
}