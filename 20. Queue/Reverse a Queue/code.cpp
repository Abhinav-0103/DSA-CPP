#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int> &q) {
    if(q.empty()) {
        return;
    }
    
    int val = q.front();
    q.pop();
    reverse(q);
    q.push(val);
}

int main() {
    queue<int> q;

    for(int i=1;i<=10;i++) {
        q.push(i);
    }

    reverse(q);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}