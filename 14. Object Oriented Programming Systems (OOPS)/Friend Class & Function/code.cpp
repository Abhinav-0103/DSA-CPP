#include<iostream>
using namespace std;

class A {
    string secret = "Secret";
    public :
        friend class B;
        friend void revealSecret(A &obj);
};

class B {
    public :
        void showSecret(A &obj) {
            cout << obj.secret << endl;
        }
};

void revealSecret(A &obj) {
    cout << obj.secret << endl;
}

int main() {
    A obj1;
    B obj2;

    obj2.showSecret(obj1);
    revealSecret(obj1);

    return 0;
}