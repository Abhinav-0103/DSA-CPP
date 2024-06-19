#include<iostream>
#include<cstring>
using namespace std;

void reverseArr(char word[], int n) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        swap(word[start], word[end]);

        start++;
        end--;
    }

    cout << word << endl;
}


int main() {
    char word[] = "apple";

    reverseArr(word, strlen(word));
}