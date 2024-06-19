#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];

    delete [] arr;
    return 0;
}