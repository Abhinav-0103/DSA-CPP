#include<iostream>
using namespace std;

int gridWays(int row, int col, int n, int m) {
    if(row == n-1 && col == m-1) {
        return 1;
    }

    if(row >= n || col >= m) {
        return 0;
    }

    int ways1 = gridWays(row,col+1,n,m);
    int ways2 = gridWays(row+1,col,n,m);

    return ways1 + ways2;
}

int main() {
    int n = 3, m = 3;

    cout << "Total Ways : " << gridWays(0,0,n,m) << endl;
}