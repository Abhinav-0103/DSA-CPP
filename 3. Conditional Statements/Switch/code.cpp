#include<iostream>
using namespace std;

int main() {
    int gender = 1;

    switch(gender) {
        case 0:
            cout << "Male" << "\n";
            break;
        
        case 1:
            cout << "Female" << "\n";
            break;
        
        default:
            ;
    }

    return 0;
}
