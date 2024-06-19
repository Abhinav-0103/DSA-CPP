#include<iostream>
using namespace std;

void print7s(int arr[][3], int n, int m) {
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 7) {
                count++;
            }
        }
    }

    cout << "Number of 7's = " << count << endl;
}

int main() {
    int arr[][3] = {{4,7,8},
                   {8,8,7}};
    int n = 2, m = 3;

    print7s(arr,n,m);

    return 0;
}