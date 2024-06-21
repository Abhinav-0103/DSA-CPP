#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void findNextGreater(vector<int> arr, vector<int> &ans) {
    stack<int> helper;
    int n = ans.size();

    ans[n-1] = -1;
    helper.push(n-1);

    for(int i=n-2;i>=0;i--) {
        int curr = arr[i];
        while(!helper.empty() && curr >= arr[helper.top()]) {
            helper.pop();
        }
        if(helper.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = arr[helper.top()];
        }

        helper.push(i);
    }
}

int main() {
    vector<int> arr = {6,8,0,1,3};
    vector<int> nextGreater = {0,0,0,0,0};

    findNextGreater(arr,nextGreater);

    for(int i=0;i<nextGreater.size();i++) {
        cout << nextGreater[i] << " ";
    }
}