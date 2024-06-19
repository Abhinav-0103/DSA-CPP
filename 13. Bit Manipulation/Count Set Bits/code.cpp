#include<iostream>
using namespace std;

int countSetBits(int num) {
    int bitMask = 1;
    int count = 0;

    while(num != 0) {
        count+=(num & bitMask);

        num = num >> 1;
    }

    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << countSetBits(num) << endl;
}