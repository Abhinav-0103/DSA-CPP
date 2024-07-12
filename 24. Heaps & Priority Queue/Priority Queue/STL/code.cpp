#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pq1;

    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    pq1.push(4);
    pq1.push(5);

    cout << "Max Heap:\n";
    while(!pq1.empty()) {
        cout << "top: " << pq1.top() << endl;
        pq1.pop(); 
    }


    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    pq2.push(4);
    pq2.push(5);

    cout << "\nMin Heap:\n";
    while(!pq2.empty()) {
        cout << "top: " << pq2.top() << endl;
        pq2.pop(); 
    }
}