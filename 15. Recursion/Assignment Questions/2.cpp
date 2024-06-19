#include<iostream>
#include<vector>
using namespace std;

void findOccurences(vector<int> arr, int i, int key) {
    if(i >= arr.size()) {
        return;
    }

    if(arr[i] == key) {
        cout << i << " ";
    }

    findOccurences(arr,i+1,key);
}

int main() {
    vector<int> arr = {3,2,4,5,6,2,7,2,2};
    int key = 2;

    findOccurences(arr,0,key);
}