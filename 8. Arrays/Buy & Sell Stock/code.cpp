#include<iostream>
#include<climits>
using namespace std;

int maxProfit(int prices[], int n) {
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    
    for(int i=1;i<n;i++) {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }

    int maxPf = 0;

    for(int i=1;i<n;i++) {
        maxPf = max(maxPf, prices[i] - bestBuy[i]);
    }

    return maxPf;
}

int main() {
    int arr[6] = {7, 6, 5, 4, 3, 2};
    int n = 6;

    int maxPf = maxProfit(arr, n);

    cout << "Max Profit = " << maxPf << endl;
    return 0;
}