#include<iostream>
using namespace std;

int pow(int x, int n) {
    if(n == 0) {
        return 1;
    }

    int halfPow = pow(x,n/2);

    if(n%2 == 0) {
        return halfPow * halfPow;
    }

    return x * halfPow * halfPow;
}

int main() {
    int x = 2;
    int n = 10;

    cout << pow(x,n) << endl;
}