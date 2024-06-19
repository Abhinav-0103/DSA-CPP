#include<iostream>
using namespace std;

class Parent {
    public :
        void show() {
            cout << "Parent Class Show" << endl;
        }

        virtual void hello() {
            cout << "Parent hello" << endl;
        }
};

class Child : public Parent {
    public :
        void show() {
            cout << "Child Class Show" << endl;
        }

        void hello() {
            cout << "Child hello" << endl;
        }
};

int main() {
    Parent *ptr;
    Child c1;

    ptr = &c1;
    ptr->hello();

    return 0;
}