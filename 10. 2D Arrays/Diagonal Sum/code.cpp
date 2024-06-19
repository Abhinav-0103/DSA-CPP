#include<iostream>
using namespace std;

void diagonalSum(int matrix[][3], int n) {
    int sum = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) {
                sum+=matrix[i][j];
            } else if(j == n-i-1) {
                sum+=matrix[i][j];
            }
        }
    }

    cout << "The diagonal sum = " << sum << endl;
}

void diagonalSumEff(int matrix[][3], int n) {
    int sum = 0;

    for(int i=0;i<n;i++) {
        sum+=matrix[i][i];
        if(i == n-i-1) {
            continue;
        }
        sum+=matrix[i][n-i-1];
    }

    cout << "The diagonal sum = " << sum << endl;
}

int main() {
    int matrix[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};
    
    int n = 3;
    diagonalSum(matrix,n);
    diagonalSumEff(matrix,n);

    return 0;
}