#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int digit;

    cout << "Enter the number : ";
    cin >> digit;

    bool isPrime = true;

    for(int i=2;i<=sqrt(digit);i++) {
        if(digit % i == 0) {
            isPrime = false;
            break;
        }
    }

    if(isPrime) {
        cout << digit << " is a prime number." << endl;
    } else {
        cout << digit << " is not a prime number." << endl;
    }

    return 0;
}