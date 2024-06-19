#include<iostream>
using namespace std;
#define X 25 // This does not use up any memory

int main() {
    const int a = 5;
    cout << "Value of constant = " << a << "\n";

    // a = 6;  NOT ALLOWED
    // const int n;  NOT ALLOWED
    return 0;
}