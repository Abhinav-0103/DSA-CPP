#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int countR = 0;
        int countL = 0;

        int ans = 0;

        for(char ch: s) {
            if(ch == 'R') {
                countR++;
            } else {
                countL++;
            }

            if(countR == countL) {
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s = "RLRLRLRLRLRL";

    int count = sol.balancedStringSplit(s);

    cout << "Count: " << count << endl;
}