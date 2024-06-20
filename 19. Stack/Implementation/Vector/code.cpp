#include<iostream>
#include<vector>
using namespace std;

class Stack {
    vector<int> s;
    int topIdx;

    public:

        Stack() {
            topIdx = -1;
        }

        void push(int val) {
            s.push_back(val);
            topIdx++;
        }

        int pop() {
            if(topIdx == -1) {
                cout << "Empty Stack" << endl;
                return -1;
            }
            int popEl = s[topIdx];
            s.pop_back();
            topIdx--;
            return popEl;
        }

        int top() {
            if(isEmpty()) {
                return -1;
            }
            return s[topIdx];
        }

        bool isEmpty() {
            if(topIdx == -1) {
                return true;
            }

            return false;
        }
};

int main() {
    Stack s;

    cout << s.pop() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    
}