#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    for(char ch: str) {
        s.push(ch);
    }
    string ans = "";

    while(!s.empty()) {
        ans = ans + s.top();
        s.pop();
    }

    return ans;
}

int main() {
    string str = "Abhinav";

    cout << reverseString(str) << endl;
}