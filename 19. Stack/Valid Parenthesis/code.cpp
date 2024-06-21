#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str) {
    stack<char> s;

    for(int i=0;i<str.length();i++) {
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if(s.empty()) {
            return false;
        } else if (ch == ')') {
            if(s.top() == '(') {
                s.pop();
            } else {
                return false;
            }
        } else if (ch == '}') {
            if(s.top() == '{') {
                s.pop();
            } else {
                return false;
            }
        } else if (ch == ']') {
            if(s.top() == '[') {
                s.pop();
            } else {
                return false;
            }
        }
    }

    if(!s.empty()) {
        return false;
    }

    return true;
}

int main() {
    string valid = "([{}]())";
    string invalid = "(}";

    cout << isValid(valid) << endl;
    cout << isValid(invalid) << endl;
}