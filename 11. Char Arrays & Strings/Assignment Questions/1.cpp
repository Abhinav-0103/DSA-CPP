#include<iostream>
#include<string>
using namespace std;

int countLowerVowels(string str) {
    int count = 0;
    for(char ch : str) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    return count;
}

int main() {
    string str;
    getline(cin,str);

    int count = countLowerVowels(str);

    cout << str << " has " << count << " lower case vowels" << endl;
    return 0;
}
