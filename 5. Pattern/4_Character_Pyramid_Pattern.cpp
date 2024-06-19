#include<iostream>
using namespace std;

int main() {
    int n = 4;
    int charVal = 65;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cout << (char)(charVal++) << " ";
        }    
        cout << endl;
    }
}