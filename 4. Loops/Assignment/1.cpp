#include<iostream>
using namespace std;

int main() {
    int digit;

    cout << "Enter a digit : ";
    cin >> digit;

    int prod = 1;

    if(digit == 0) {
        cout << "The factorial = " << prod << endl;
        return 0;
    }

    for(int i=1;i<=digit;i++) {
        prod = prod * i;
    }

    cout << "The factorial = " << prod << endl;
    
    return 0;
}