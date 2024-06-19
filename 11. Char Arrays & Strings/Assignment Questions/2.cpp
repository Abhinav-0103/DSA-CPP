#include<iostream>
#include<string>
using namespace std;

bool isValidAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }
    
    int count[26] = {0};

    for(char ch : str1) {
        count[ch - 'a']++;
    }

    for(char ch : str2) {
        if(count[ch - 'a'] == 0) {
            return false;
        }
        count[ch - 'a']--;
    }

    return true;
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    bool isAnagram = isValidAnagram(str1, str2);
 cout << (int)('0');
    if(isAnagram) {
        for(int i=0;i<str1.length();i++) {
            if(str1[i] != str2[i]) {
                int idx = str1.find(str2[i]);
                swap(str1[i], str1[idx]);

                if(str1 == str2) {
                    cout << "True" << endl;
                } else {
                    cout << "False" << endl;
                }

                return 0;
            }
        }

        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}