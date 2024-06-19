#include<iostream>
using namespace std;

void secRowSum(int arr[][3], int n, int m) {
    int sum = 0;

    for(int i=0;i<m;i++) {
        sum+=arr[1][i];
    }

    cout << "Sum of second row = " << sum << endl;
}

int main() {
    int arr[][3] = {{1,4,9},
                   {11,4,3},
                   {2,2,3}};
    int n = 3, m = 3;

    secRowSum(arr,n,m);

    return 0;
}