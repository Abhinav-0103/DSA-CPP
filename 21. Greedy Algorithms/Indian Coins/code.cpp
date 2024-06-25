#include<iostream>
#include<vector>
using namespace std;

int minCoins(vector<int> coins, int V) {
    int count = 0;
    int n = coins.size();
    for(int i=n-1;i>=0 && V>0;i--) {
        if(V >= coins[i]) {
            count += V / coins[i];
            cout << "Coin: " << coins[i] << "; Count: " << V / coins[i] << endl;
            V = V % coins[i];
        }
    }

    return count;
}

int main() {
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int V = 1099;

    int minCoinsReq = minCoins(coins,V);

    cout << "Min Coins Required: " << minCoinsReq << endl;
}