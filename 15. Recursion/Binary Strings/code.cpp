#include<iostream>
using namespace std;

void binaryString(int n, char lastPlace, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(lastPlace != '1') {
        binaryString(n-1,'0',ans+'0');
        binaryString(n-1,'1',ans+'1');
    } else {
        binaryString(n-1,'0',ans+'0');
    }
}

int main() {
    binaryString(4,'0',"");

    return 0;
}