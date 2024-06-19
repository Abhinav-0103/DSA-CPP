#include<iostream>
using namespace std;

int clearIthBit(int num, int i) {
    int bitMask = ~(1 << i);

    return num & bitMask;
}

int main() {
    int num, i;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter ith position: ";
    cin >> i;

    cout << "Number after bit set: " << clearIthBit(num, i) << endl;
}