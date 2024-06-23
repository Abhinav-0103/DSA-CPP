#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> deq;

    deq.push_front(1);
    deq.push_back(2);

    deq.push_back(3);
    deq.push_front(4);

    while(!deq.empty()) {
        cout << deq.front() << " ";
        deq.pop_front();
    }
}