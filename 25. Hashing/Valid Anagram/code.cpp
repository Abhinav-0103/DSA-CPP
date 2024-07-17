#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool validAnagram(string s1, string s2) {
    unordered_map<char, int> map;

    if(s1.length() != s2.length()) {
        return false;
    }

    for(char ch: s1) {
        if(map.count(ch) == 0) {
            map[ch] = 1;
        } else {
            map[ch] = map[ch] + 1;
        }
    }

    for(char ch: s2) {
        if(map.count(ch) == 0) {
            return false;
        } else {
            if(map[ch] == 0) {
                return false;
            }

            map[ch] = map[ch] - 1;
        }
    }

    return true;
}

int main() {
    string s1 = "race";
    string s2 = "care";

    if(validAnagram(s1,s2)) {
        cout << "Valid Anagram" << endl;
    } else {
        cout << "Invalid Anagram" << endl;
    }
}