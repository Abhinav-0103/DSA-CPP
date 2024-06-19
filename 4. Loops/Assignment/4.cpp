#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int digit;
    cout << "Enter a digit : ";
    cin >> digit;

    bool isPrime = true;

    for(int i=2;i<=digit;i++) {
        for(int j=2;j<=sqrt(i)+1;j++) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if(isPrime) {
            cout << i << "\n";
        }

        isPrime = true;
    }

    return 0;
}