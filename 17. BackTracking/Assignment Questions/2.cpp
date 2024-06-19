#include<iostream>
#include<string>
using namespace std;

void keypadCombUtils(string digits, string helper[], string ans) {
    if(digits.length() == 0) {
        cout << ans << endl;
        return;
    }

    string digit(1, digits[0]);
    int n = helper[stoi(digit)].length();

    for(int i=0;i<n;i++) {
        char c = helper[stoi(digit)][i];
        if(digits.length() > 1) {
            keypadCombUtils(digits.substr(1, digits.length()-1),helper,ans+c);
        } else {
            keypadCombUtils("",helper,ans+c);
        }
    }
}

void keypadComb(string digits) {
    string helper[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    keypadCombUtils(digits, helper, "");
}

int main() {
    string digits = "23";
    keypadComb(digits);
}