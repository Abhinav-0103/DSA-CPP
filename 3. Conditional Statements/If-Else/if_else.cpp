#include<iostream>
using namespace std;

int main() {
    int age = 18; 

    if(age >= 18) {
        cout << "Can vote" << "\n";
    } else if(age < 18) {
        cout << "Cannot Vote" << "\n";
    }

    return 0;
}