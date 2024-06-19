#include<iostream>
#include<cstring>
using namespace std;

void toUpper(char word[], int n) {
    for(int i=0;i<n;i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            continue;
        } else {
            char temp = word[i] - 'a' + 'A';
            word[i] = temp;
        }
    }

    cout << word << endl;
}

void toLower(char word[], int n) {
    for(int i=0;i<n;i++) {
        if(word[i] >= 'a' && word[i] <= 'z') {
            continue;
        } else {
            char temp = word[i] - 'A' + 'a';
            word[i] = temp;
        }
    }

    cout << word << endl;
}

int main() {
    char word[] = "ApPle";

    toUpper(word, strlen(word));
    toLower(word, strlen(word));
}