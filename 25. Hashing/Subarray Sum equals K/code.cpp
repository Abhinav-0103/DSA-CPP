#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subArrEqK(vector<int> arr, int K) {
    unordered_map<int, int> map;
    int count = 0;
    int sum = 0;
    
    map[0] = 1;
    for(int i=0;i<arr.size();i++) {
        sum += arr[i];

        if(map.count(sum - K) != 0) {
            count += map[sum-K];
        }

        if(map.count(sum) == 0 ) {
            map[sum] = 1;
        } else {
            map[sum] = map[sum] + 1;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {10,2,-2,-20,10};
    int K = -10;

    int count = subArrEqK(arr, K);

    cout << "Count: " << count << endl;
}