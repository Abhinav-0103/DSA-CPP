#include<iostream>
using namespace std;

class Queue {
    int* arr;

    int capacity;
    int currSize;

    int f, r;

    public :
        Queue(int n) {
            capacity = n;
            arr = new int[capacity];
            f = 0;
            r = -1;
            currSize = 0;
        }

        void push(int val) {
            if(currSize == capacity) {
                cout << "Queue is full" << endl;
                return;
            }

            r = (r + 1) % capacity;

            arr[r] = val;
            currSize++;
        }

        void pop() {
            if(currSize == 0) {
                cout << "Queue is empty" << endl;
                return;
            }

            f = (f + 1) % capacity;
            currSize--;
        }

        int front() {
            if(currSize != 0) {
                return arr[f];
            } else {
                return -1;
            }
        }

        bool empty() {
            return currSize == 0;
        }
};

int main() {
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    q.push(5);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

}