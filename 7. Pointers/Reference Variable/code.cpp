#include<iostream>
using namespace std;

int main() {
    int a = 10;
    int &b = a;
    cout << "a = " << a << endl;
    b = 25;
    cout << "a = " << a << endl;
}