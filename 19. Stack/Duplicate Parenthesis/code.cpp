#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;

    for(int i=0;i<str.length();i++) {
        char ch = str[i];

        if(ch != ')') {
            s.push(ch);
        } else {
            if(s.top() == '(') {  // It is a Valid String
                return true;
            }

            while(s.top() != '(') {
                s.pop();
            }

            s.pop();
        }
    }

    return false;
}

int main() {
    string no_dup = "((a+b)+(c+d))";
    string dup = "((a+b))";

    cout << isDuplicate(no_dup) << endl;
    cout << isDuplicate(dup) << endl;
}