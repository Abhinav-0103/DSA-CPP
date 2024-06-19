#include<iostream>
using namespace std;

int main() {
    cout << "Int to Float " << (10 / 3.0) << "\n"; // Implicit Type conversion
    cout << "Char to Int " << ('A' + 1) << "\n"; // Implicit Type conversion

    cout << "Explicit Char " << (char)('A' + 1) << "\n";
    
    return 0;
}