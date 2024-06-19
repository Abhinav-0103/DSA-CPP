#include<iostream>
#define PI 3.14
using namespace std;

int main() {
    float r;
    cout<<"Enter the radius : ";
    cin>>r;

    float area = PI * r * r;

    cout<<"The area of the circle = "<< area <<"\n";
    return 0;
}