#include<iostream>
#include<cstring>
using namespace std;

bool isValidPalindrome(char word[], int n) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        if(word[start] != word[end]) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}


int main() {
    char word[] = "malayalam";

    if(isValidPalindrome(word, strlen(word))) {
        cout << word << " : Valid Palindrome" << endl;
    } else {
        cout << word << " : Invalid Palindrome" <<endl;
    }
}