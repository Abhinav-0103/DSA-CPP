#include<iostream>
using namespace std;

int findSubStr(string str, int idx) {
    if(idx == str.length()) {
        return 0;
    }
    int count = 0;
    for(int i=0;i<str.length()-idx;i++) {
        string subStr = str.substr(idx,i+1);

        if(subStr[0] == subStr[subStr.length()-1]) {
            count+=1;
        }
    }

    return count + findSubStr(str,idx+1);
}

void printSubStr(string str, int idx) {
    if(idx == str.length()) {
        return;
    }
    for(int i=0;i<str.length()-idx;i++) {
        
        cout << idx << "," << i << " ";
        string subStr = str.substr(idx,i+1);

        cout << subStr << endl;
    }

    return printSubStr(str,idx+1);
}

int main() {
    string str = "aba";
    // printSubStr(str,0);

    cout << "Count: " << findSubStr(str, 0) << endl;

    return 0;
}