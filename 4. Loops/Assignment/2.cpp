#include<iostream>
using namespace std;

int main() {
    int digit;

    cout << "Enter a digit : ";
    cin >> digit;

    for(int i=1;i<=10;i++) {
        cout << digit << " * " << i << " = " << i * digit << "\n";
    }

    return 0;
}