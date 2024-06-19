#include<iostream>
#include<cmath>
using namespace std;

int decToBin(int decNum) {
    int i = decNum;
    int sum = 0, powerCount = 0;
    while(i > 0 ) {
        int rem = i % 2;
        sum = sum + (rem * pow(10, powerCount));
        powerCount++;
        i/=2;
    }

    return sum; 
}

int main() {
    int decNum = 32;

    int binNum = decToBin(decNum);

    cout << "The binary form of " << decNum << " = " << binNum << endl;
    return 0;
}