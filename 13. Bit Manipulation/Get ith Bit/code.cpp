#include<iostream>
using namespace std;

int getIthBit(int num, int i) {
    int bitMask = 1 << i;

    if(num & bitMask) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num, i;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter ith position: ";
    cin >> i;

    if(getIthBit(num, i)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}