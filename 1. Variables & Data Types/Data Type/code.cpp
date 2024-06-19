#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int a = 5;
    long b = 6;
    bool c = true;
    char d = '@';

    float e = 3.14159265359;
    double f = 3.14159265359;

    cout<<setprecision(12)<<"Float e = "<< e <<"\nDouble f = "<< f <<"\n";

    return 0;
}