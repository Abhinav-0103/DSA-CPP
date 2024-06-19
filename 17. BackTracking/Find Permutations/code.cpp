#include<iostream>
#include<string>
using namespace std;

static int counter = 1;

void findPermutation(string str, string ans) {
    if(str.length() == 0) {
        cout << counter << ". " << ans << "\n";
        counter++;
        return;
    }

    int n = str.length();

    for(int i=0;i<n;i++) {
        string subStr = str.substr(0,i) + str.substr(i+1,n-i-1);
        findPermutation(subStr,ans+str[i]);
    }
}

int main() {
    string str = "abcd";

    findPermutation(str,"");

    return 0;
}