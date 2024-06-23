#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    cout << "Size: " << n << endl;
    queue<int> helper;

    for(int i=0;i<n/2;i++) {
        helper.push(q.front());
        q.pop();    
    }

    while(!helper.empty()) {
        q.push(helper.front());
        q.push(q.front());
        helper.pop();
        q.pop();
    }
}

int main() {
    queue<int> q;

    for(int i=1;i<=10;i++) {
        q.push(i);
    }

    interleave(q);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}