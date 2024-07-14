#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    for(int el: s) {
        cout << el << endl;
    }

    s.erase(3);

    if(s.find(3) != s.end()) { // s.end() == NULL
        cout << "3 exists" << endl;
    } else {
        cout << "3 does not exist" << endl;
    }
}