#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n for Fibonacci : ";
    cin >> n;

    int x = 0, y = 1;

    if(n <= 0) {
        cout << x;
    } else if(n == 1) {
        cout << x << " " << y;
    } else {
        cout << x << " " << y << " ";

        int z;
        for(int i=1;i<n;i++) {
            z = x + y;
            cout << z << " ";

            x = y;
            y = z;
        }
    }

    return 0;
}