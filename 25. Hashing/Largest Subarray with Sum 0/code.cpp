#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int largestSubArr(vector<int> arr) {
    int sum = 0;
    unordered_map<int, int> map;
    int maxLen = -1;
    int currLen;

    for(int i=0;i<arr.size();i++) {
        sum += arr[i];

        if(map.count(sum) == 0) {
            map[sum] = i;
        } else {
            currLen = i - map[sum];
            maxLen = max(maxLen, currLen);
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {15,-2,2,-8,1,7,10};

    int len = largestSubArr(arr);

    cout << "Length: " << len << endl;
}