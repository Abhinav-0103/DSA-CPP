#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int minAbsDiff(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int minDiff = 0;

    for(int i=0;i<a.size();i++) {
        minDiff += abs(a[i] - b[i]);
    }

    return minDiff;
}

int main() {
    vector<int> a = {4,1,8,7};
    vector<int> b = {2,3,6,5};

    int minDiff = minAbsDiff(a,b);

    cout << "Min Absolute Difference: " << minDiff << endl;
}