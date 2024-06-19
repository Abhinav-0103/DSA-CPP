#include<iostream>
using namespace std;

bool atLeastTwice(int arr[], int n) {
    for(int i=0;i<n;i++) {
        int count = 1;
        for(int j=i+1;j<n;j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        if(count >= 2) {
            return true;
        }
    }

    return false;
}

int main() {
    int arr[] = {1,1,1,3,3,4,3,2,4,2};
    int n = sizeof(arr) / sizeof(int);

    cout << atLeastTwice(arr, n) << endl;

    return 0;
}