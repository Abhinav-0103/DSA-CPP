#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isOdd(char ch) {
        return (ch - '0') & 1;
    }

    string largestOddNumber(string num) {
        int n = num.size();

        if(isOdd(num[n-1])) {
            return num;
        }

        int idx = -1;

        for(int i=n-2;i>=0;i--) {
            if(isOdd(num[i])) {
                idx = i;
                break;
            }
        }

        return idx == -1 ? "" : num.substr(0,idx+1);
    }
};

int main() {
    Solution sol;
    string num = "54236";

    string ans = sol.largestOddNumber(num);

    cout << "Answer: " << ans << endl;
}