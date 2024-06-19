#include<iostream>
using namespace std;

int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    int way1 = friendsPairing(n-1);
    int way2 = (n-1) * friendsPairing(n-2);

    return way1 + way2;
}

int main() {
    int n = 4;
    cout << "ways: " << friendsPairing(n) << endl;
}