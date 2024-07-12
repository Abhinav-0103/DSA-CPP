#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int> v) {
    for(int i: v) {
        cout << i << " ";
    }
    cout << endl;
}

void heapify(vector<int> &vec, int i, int n) {
    if(i >= vec.size()) {
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int maxIdx = i;

    if(left < n && vec[left] > vec[maxIdx]) {
        maxIdx = left;
    }

    if(right < n && vec[right] > vec[maxIdx]) {
        maxIdx = right;
    }

    swap(vec[i], vec[maxIdx]);

    if(i != maxIdx) {
        heapify(vec,maxIdx,n);
    }   
}

void heapSort(vector<int> &vec) {
    int n = vec.size();

    for(int i=n/2-1;i>=0;i--) {
        heapify(vec,i,n);
    }

    for(n=n;n>0;n--) {
        swap(vec[0], vec[n-1]);
        heapify(vec,0,n-1);
    }
}

int main() {
    vector<int> vec = {1,4,2,5,3};

    heapSort(vec);

    printVec(vec);
}