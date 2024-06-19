#include<iostream>
using namespace std;

bool search(int matrix[][4], int n, int m, int key) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == key) {
                cout << "Found " << key << " at (" << i << "," << j << ")" << endl;
                return true;
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