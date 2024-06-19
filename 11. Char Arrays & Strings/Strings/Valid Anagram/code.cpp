#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }

    int count[26] = {0};

    for(char ch : str1) {
        count[ch - 'a']++;
    }

    for(char ch : str2) {
        if(count[ch - 'a'] != 0) {
            count[ch - 'a']--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string str1 = "anagram";
    string str2 = "nagaram";

    if(isAnagram(str1, str2)) {
        cout << str1 << " and " << str2 << " are Anagrams" << endl;
    } else {
        cout << str1 << " and " << str2 << " are not Anagrams" << endl;
    }

    return 0;
}