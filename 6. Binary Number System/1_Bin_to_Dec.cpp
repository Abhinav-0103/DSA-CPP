#include<iostream>
#include<cmath>
using namespace std;

int binToDec(int binNum) {
    int i = binNum;
    int powerCount = 0;
    int sum = 0;

    while(i > 0) {
        int lastDig  = i % 10;
        sum = sum + (lastDig * pow(2, powerCount++));
        i/=10;
    }

    return sum;
}

int main() {
    int binNum = 101001;
    int dec = binToDec(binNum);
    cout << "Decimal value of " << binNum << " = " << dec << endl;
    return 0;
}