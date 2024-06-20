#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &s, int val) {
    if(s.empty()) {
        s.push(val);
        return;
    }
    int top = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(top);
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    pushAtBottom(s,5);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}