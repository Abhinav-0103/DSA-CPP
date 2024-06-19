#include<iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int bitMask = 1;

    if((num & bitMask) == 1) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
}