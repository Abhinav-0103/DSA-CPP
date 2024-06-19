#include<iostream>
using namespace std;

int clearIthBit(int num, int i) {
    int bitMask = ~(1 << i);

    return num & bitMask;
}

int setIthBit(int num, int i) {
    int bitMask = 1 << i;

    return num | bitMask;
}

int updateIthBit(int num, int i, int val) {
    if(val == 0) {
        return clearIthBit(num, i);
    } else {
        return setIthBit(num, i);
    }
}

int updateIthBit2(int num, int i, int val) {
    int temp = clearIthBit(num, i);

    return temp | (val << i);
}

int main() {
    int num, i, val;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter ith position: ";
    cin >> i;

    cout << "Enter value: ";
    cin >> val;

    cout << "Number after updating the bit: " << updateIthBit2(num, i, val) << endl;
}