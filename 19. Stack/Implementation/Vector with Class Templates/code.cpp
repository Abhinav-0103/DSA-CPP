#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack {
    vector<T> s;
    int topIdx;

    public:

        Stack() {
            topIdx = -1;
        }

        void push(T val) {
            s.push_back(val);
            topIdx++;
        }

        T pop() {
            if(topIdx == -1) {
                cout << "Empty Stack" << endl;
                return -1;
            }
            int popEl = s[topIdx];
            s.pop_back();
            topIdx--;
            return popEl;
        }

        T top() {
            // if(isEmpty()) {
            //     return -1;
            // }
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
    Stack<char> s;

    cout << s.pop() << endl;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    while(!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    
}