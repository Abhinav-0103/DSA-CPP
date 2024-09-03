#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n--) {
            int i = (k - 26 * n) <= 0 ? 1 : (k - 26 * n);

            for(;i<=26;i++) {
                if((k - i) <= (n * 26)) {
                    k = k - i;
                    ans.push_back((char)(96 + i));
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    int n = 99520;
    int k = 873215;

    Solution sol;

    cout << sol.getSmallestString(n, k) << endl;
}