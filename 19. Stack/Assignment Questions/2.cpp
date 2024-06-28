#include<iostream>
#include<stack>
#include<string>
using namespace std;

string decode(string str) {
    stack<int> s;
    string ans = "";

    for(int i=0;i<str.length();i++) {
        if(str[i] != ']') {
            s.push(str[i]);
        } else {
            string temp = "";
            while(!s.empty() && s.top() != '[') {
                temp += s.top();
                s.pop();
            }

            string revTemp = "";

            for(int i=temp.length()-1;i>=0;i--) {
                revTemp += temp[i];
            }

            s.pop();
            int count = s.top() - '0';
            s.pop();

            for(int j=0;j<count;j++) {
                ans += revTemp;
            }
        }
    }

    return ans;
}

int main() {
    string str = "3[a]2[bc]4[abc]";

    string decoded = decode(str);

    cout << decoded << endl;
}