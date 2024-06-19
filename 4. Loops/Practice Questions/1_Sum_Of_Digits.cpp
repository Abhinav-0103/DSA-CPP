#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int counter = 0;
    int sum = 0;
    int digit, rem;

    cout << "Enter a digit : ";
    cin >> digit;
    for(int i=digit;i>0;i/=10) {
        rem = i % 10;

        sum = sum + (rem * pow(10, counter));
    }

    cout << "The sum of digits = " << sum << endl;
    return 0;
}