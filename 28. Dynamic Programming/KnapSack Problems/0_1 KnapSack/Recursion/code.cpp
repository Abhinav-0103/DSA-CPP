#include<iostream>
#include<vector>
using namespace std;

int knapSack(int n, int W, vector<int> val, vector<int> wt) {
    if(n == 0 || W == 0) {
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W) {
        int include = knapSack(n-1, W-itemWt, val, wt) + itemVal;
        int exclude = knapSack(n-1, W, val, wt);

        return max(include, exclude);
    } else {
        return knapSack(n-1, W, val, wt);
    }
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int W = 7;
    int n = val.size();

    int ans = knapSack(n,W,val,wt);

    cout << "Max Profit: " << ans << endl;

    return 0;
}