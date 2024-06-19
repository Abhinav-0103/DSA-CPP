#include<iostream>
#include<vector>
using namespace std;

int lastOcc(vector<int> arr, int i, int num) {
    if(i == arr.size()) {
        return -1;
    }

    int idx = lastOcc(arr,i+1,num);

    if(idx == -1) {
        if(arr[i] == num) {
            return i;
        }
    }

    return idx;
}

int main() {
    vector<int> arr = {1, 3, 3, 3, 5};
    int num = 3;

    cout << "First Occurence of " << num << " is at idx: " << lastOcc(arr,0,num) << endl;
    return 0;
}