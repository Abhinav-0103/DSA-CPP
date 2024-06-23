#include<iostream>
#include<queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

    public :
        void push(int val) {
            if(empty()) {
                q1.push(val);
                return;
            } else if(q1.empty()) {
                while(!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }

                q2.push(val);

                while(!q1.empty()) {
                    q2.push(q1.front());
                    q1.pop();
                }
            } else {
                while(!q1.empty()) {
                    q2.push(q1.front());
                    q1.pop();
                }

                q1.push(val);

                while(!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }

        void pop() {
            if(empty()) {
                cout << "Stack is full" << endl;
                return;
            }

            if(q1.empty()) {
                q2.pop();
            } else {
                q1.pop();
            }
        }

        int top() {
            if(empty()) {
                cout << "Stack is full" << endl;
                return -1;
            }

            if(q1.empty()) {
                return q2.front();
            }
            return q1.front();    
        }

        bool empty() {
            return q1.empty() && q2.empty();
        }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}