#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mcm(vector<int> arr, int i, int j) {
    if(i == j) {
        return 0;
    }

    int minCost = INT_MAX;

    for(int k=i;k<j;k++) {
        int cost1 = mcm(arr,i,k);
        int cost2 = mcm(arr,k+1,j);

        int total = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        minCost = min(minCost, total);
    }

    return minCost;
}

int main() {
    vector<int> arr = {1,2,3,4,3};

    int minCost = mcm(arr,1,arr.size()-1);

    cout << "Min Cost: " << minCost << endl;
}