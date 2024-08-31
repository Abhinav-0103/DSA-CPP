#include<iostream>
using namespace std;

int fastExpo(int num, int pow) {
    int ans = 1;
    int bitMask = 1;

    while(pow) {
        int lastBit = pow & 1;

        if(lastBit == 1) {
            ans = ans * num;
            num = num * num;
        } else {
            num = num * num;
        }

        pow = pow >> 1;
    }

    return ans;
}

int main() {
    int num, pow;

    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the power: ";
    cin >> pow;

    cout << fastExpo(num, pow) << endl;
}