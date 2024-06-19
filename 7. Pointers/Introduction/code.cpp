#include<iostream>
using namespace std;

int main() {
    int a = 10;
    int *ptr = &a;
    int **pptr = &ptr;

    float b = 3.14;
    float *ptr2 = &b;

    double c = 3.123; 
    double *ptr3 = &c;

    cout << "Value stored in ptr " << ptr << endl;
    cout << "value at address in ptr " << *ptr << endl;
    cout << "Address of a " << &a << endl;

    cout << "Size of int pointer = " << sizeof(ptr) << endl;
    cout << "Size of float pointer = " << sizeof(ptr2) << endl;
    cout << "Size of double pointer = " << sizeof(ptr3) << endl;

    cout << "Address of ptr = " << &ptr << endl;
    cout << "Value of pptr = " << pptr << endl;

    return 0;
}