#include<iostream>
using namespace std;

class Complex {
    int real;
    int img;

    public:
        Complex(int r, int i) {
            real = r;
            img = i;
        }

        void showNum() {
            cout << real << "+" << img << "i" << endl;
        }

        Complex operator + (Complex c2) {
            return Complex(this->real + c2.real, this->img + c2.img);
        }

        Complex operator - (Complex c2) {
            return Complex(this->real - c2.real, this->img - c2.img);
        }
};

int main() {
    Complex c1(3, 4);
    Complex c2(2, 5);

    c1.showNum();
    c2.showNum();

    Complex c3 = c1 + c2;
    c3.showNum();

    Complex c4 = c1 - c2;
    c4.showNum();

    return 0;
}