#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void reverseUtil(queue<int> &q, int k) {
    if(k == 0) {
        return;
    }

    int val = q.front();
    q.pop();

    reverseUtil(q,k-1);

    q.push(val);
}

void reverse(queue<int> &q, int k) {
    int n = q.size();

    reverseUtil(q,k);

    for(int i=0;i<(n-k);i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int k = 6;

    queue<int> q;

    for(int i: arr) {
        q.push(i);
    }

    reverse(q,k);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}