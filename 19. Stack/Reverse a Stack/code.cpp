#include<iostream>
#include<stack>
#include<string>
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

void reverse(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int top = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s,top);
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse(s);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}