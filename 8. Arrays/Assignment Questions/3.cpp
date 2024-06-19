#include<iostream>
#include<climits>
using namespace std;

int largestProd(int arr[], int n) {
    int maxProd = arr[0];
    int minProd = arr[0];
    int ans = maxProd;
    int prod = 1;
    cout << "Min Prod: " << minProd << endl;
    cout << "Max Prod: " << maxProd << endl;
    cout << endl;
    
    for(int i=1;i<n;i++) {
        int curr = arr[i];

        prod = max(curr, max(maxProd * curr, minProd * curr));
        minProd = min(curr, min(maxProd * curr, minProd * curr));
        maxProd = prod;
        cout << "Min Prod: " << minProd << endl;
        cout << "Max Prod: " << maxProd << endl;
        cout << endl;

        ans = max(ans, maxProd);
    }

    return ans;
}

int main() {
    int arr[] = {2,-1,-4,0};
    int n = sizeof(arr) / sizeof(int);

    cout << "Largest Product = " << largestProd(arr, n) << endl;
}