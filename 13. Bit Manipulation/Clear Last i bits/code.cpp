#include<iostream>
using namespace std;

int clearIBits(int num, int i) {
    int bitMask = (~0) << i;

    return num & bitMask;
}

int main() {
    int num, i, val;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter ith position: ";
    cin >> i;

    cout << "Number after clearing the bits: " << clearIBits(num, i) << endl;
}