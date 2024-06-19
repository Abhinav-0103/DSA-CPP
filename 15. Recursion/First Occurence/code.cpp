#include<iostream>
#include<vector>
using namespace std;

int firstOcc(vector<int> arr, int i, int num) {
    if(i == arr.size()) {
        return -1;
    }

    if(arr[i] == num) {
        return i;
    }

    return firstOcc(arr,i+1,num);
}

int main() {
    vector<int> arr = {1, 3, 3, 3, 3};
    int num = 2;

    cout << "First Occurence of " << num << " is at idx: " << firstOcc(arr,0,num) << endl;
    return 0;
}