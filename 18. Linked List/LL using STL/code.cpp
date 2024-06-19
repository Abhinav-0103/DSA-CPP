#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main() {
    list<int> ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    list<int>::iterator itr;

    for(itr=ll.begin();itr!=ll.end();itr++) {
        cout << (*itr) << "->";
    }

    ll.insert(ll.begin(), 7, 5);

    cout << endl;
    for(itr=ll.begin();itr!=ll.end();itr++) {
        cout << (*itr) << "->";
    }
}