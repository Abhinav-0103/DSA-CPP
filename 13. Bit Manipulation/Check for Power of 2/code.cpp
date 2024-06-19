#include<iostream>
using namespace std;

bool checkPower2(int num) {
    if(!(num & num-1)) {
        return true;
    }

    return false;
}

int main() {
    int num, i;
    cout << "Enter a number: ";
    cin >> num;

    if(checkPower2(num)) {
        cout << "Power of 2" << endl;
    } else {
        cout << "Not a Power of 2" << endl;
    }
}