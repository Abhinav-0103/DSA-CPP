#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> arr, int i) {
    if(i == arr.size()-1) {
        return true;
    }

    if(arr[i] > arr[i+1]) {
        return false;
    }

    if(isSorted(arr,i+1)) {
        return true;
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    if(isSorted(arr,0)) {
        cout << "The array is sorted" << endl;
    } else {
        cout << "The array is not sorted" << endl;
    }
    return 0;
}