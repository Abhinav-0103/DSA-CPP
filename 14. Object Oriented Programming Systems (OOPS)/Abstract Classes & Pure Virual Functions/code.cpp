#include<iostream>
using namespace std;

class Shape {
    public :
        virtual void draw() = 0;
};

class Circle : public Shape {
    public :
        void draw() {
            cout <<"Draw Circle" << endl;
        }
};

int main() {
    Circle c1;

    c1.draw();

    return 0;
}