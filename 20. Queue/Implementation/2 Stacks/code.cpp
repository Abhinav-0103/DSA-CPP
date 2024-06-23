#include<iostream>
#include<stack>
using namespace std;

class Queue1 {
    stack<int> s1, s2;

    public :
        void push(int val) {
            if(s1.empty()) {
                s1.push(val);
            } else {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }

                s1.push(val);

                while(!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }

        void pop() {
            if(s1.empty()) {
                cout << "Stack is Empty" << endl;
                return;
            }
            s1.pop();
        }

        int front() {
            if(s1.empty()) {
                return -1;
            }
            return s1.top();
        }

        bool empty() {
            return s1.empty();
        }
};

class Queue2 {
    stack<int> s1, s2;

    public :
        void push(int val) {
            s1.push(val);
        }

        void pop() {
            if(s1.empty()) {
                cout << "Queue is empty" << endl;
                return;
            }

            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            s2.pop();

            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        int front() {
            if(s1.empty()) {
                return -1;
            }
            
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            int val = s2.top();

            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }

            return val;
        }

        bool empty() {
            return s1.empty();
        }
};

int main() {
    Queue1 q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.pop();

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    Queue2 q2;

    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);

    q2.pop();

    while(!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
}