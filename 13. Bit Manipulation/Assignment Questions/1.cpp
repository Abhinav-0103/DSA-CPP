#include<iostream>
using namespace std;

int clearRange(int num, int i, int j) {
    int bitMask1 = (~0) << (j+1);
    int bitMask2 = ~((~0) << i);

    int bitMask = bitMask1 | bitMask2;

    return num & bitMask;
}

int main() {
    int num, i, j;

    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter start of range: ";
    cin >> i;
    cout << "Enter end of range: ";
    cin >> j;

    cout << clearRange(num,i,j) << endl;
}