#include<iostream>
using namespace std;

int main() {
    float pencil, pen, eraser;
    cout<<"Enter the price of a pencil : ";
    cin>>pencil;
    cout<<"Enter the price of a pen : ";
    cin>>pen;
    cout<<"Enter the price of an eraser : ";
    cin>>eraser;

    float totalAmount = (pencil + 0.18 * pencil) + (pen + 0.18 * pen) + (eraser + 0.18 * eraser);

    cout<<"Your total amount = "<< totalAmount <<"\n";
    return 0;
}