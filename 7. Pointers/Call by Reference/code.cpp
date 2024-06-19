#include<iostream>
using namespace std;

void changeA(int *ptr) {
    *ptr = 20;
}

int main() {
    int a = 10;
    cout << "a = " << a << endl;
    changeA(&a);
    cout << "a = " << a << endl;

    return 0;
}