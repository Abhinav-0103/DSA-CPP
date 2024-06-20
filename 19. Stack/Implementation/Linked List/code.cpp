#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<class T>
class Stack {
    list<T> s;

    public:
        void push(T val) {
            s.push_back(val);
        }

        T pop() {
            T val = *s.end();
            s.pop_back();
            return val;
        }

        T top() {
            return *s.end();
        } 

        bool isEmpty() {
            return s.empty();
        }
};

int main() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    cout << s.top() << endl; 
}