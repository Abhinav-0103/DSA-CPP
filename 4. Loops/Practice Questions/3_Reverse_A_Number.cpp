#include<iostream>
using namespace std;

int main() {
    int digit;

    cout << "Enter a digit : ";
    cin >> digit;

    int i = digit, sum = 0;

    while(i > 0) {
        int rem = i % 10;

        sum = (sum * 10) + rem;

        i/=10;
    }

    cout << "Reversed Number = " << sum << endl;

    return 0;
}