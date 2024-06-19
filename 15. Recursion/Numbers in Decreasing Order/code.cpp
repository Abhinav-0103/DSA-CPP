#include<iostream>
using namespace std;

void printDec(int n) {
    if(n == 0) {
        cout << endl;
        return;
    }

    cout << n << " ";
    printDec(n-1);
}

int main() {
    printDec(5);
    return 0;
}