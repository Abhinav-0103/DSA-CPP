#include<iostream>
#include<list>
using namespace std;

template <class T>
class Queue {
    public:
        list<T> ll;

        void push(T val) {
            ll.push_back(val);
        }

        void pop() {
            ll.pop_front();
        }

        int front() {
            return *ll.begin();
        }

        bool empty() {
            return ll.empty();
        }
};

int main() {
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}