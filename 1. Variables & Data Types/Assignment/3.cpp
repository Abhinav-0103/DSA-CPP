#include<iostream>
using namespace std;

int main() {
    float p, r, t;
    cout<<"Enter the Principal amount : ";
    cin>>p;
    cout<<"Enter the Rate of Interest : ";
    cin>>r;
    cout<<"Enter the Time period (in years) : ";
    cin>>t;

    float si = (p * r * t) / 100;

    cout<<"Simple Interest = Rs."<< si <<"\n";
    return 0;
}