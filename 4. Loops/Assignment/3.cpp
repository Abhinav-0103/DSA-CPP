#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int digit;

    cout << "Enter a digit : ";
    cin >> digit;

    int sum = 0, i = digit;

    while(i > 0) {
        int lastDig = i % 10;
        int cube = pow(lastDig, 3);
        sum = sum + cube;
        cout << cube << " " << sum << endl;
        i/=10;
    }

    cout << "Sum = " << sum << endl;

    if(digit == sum) {
        cout << digit << " is an Armstrong number" << endl;
    } else {
        cout << digit << " is not an Armstrong number" << endl;
    }

    return 0;
}