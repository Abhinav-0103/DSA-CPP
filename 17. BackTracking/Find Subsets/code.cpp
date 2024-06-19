#include<iostream>
#include<string>
using namespace std;

static int i = 1;

void findSubsets(string str, string substr) {
    if(str.length() == 0) {
        cout << i << ". " << substr << "\n";
        i++;
        return;
    }

    char ch = str[0];
    int n = str.length();

    findSubsets(str.substr(1,n-1), substr+ch);
    findSubsets(str.substr(1,n-1), substr);
}

int main() {
    string str = "abcde";

    findSubsets(str, "");

    return 0;
}