#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void printUnion(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;
    cout << "Union: ";

    for(int i: arr1) {
        s.insert(i);
    }

    for(int i: arr2) {
        s.insert(i);
    }

    for(int i: s) {
        cout << i << " ";
    }

    cout << endl;
}

void printIntersection(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;
    cout << "Intersection: ";

    for(int i: arr1) {
        s.insert(i);
    }

    for(int i: arr2) {
        if(s.find(i) != s.end()) {
            cout << i << " ";
            s.erase(i);
        }
    }

    cout << endl;
}

int main() {
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};

    printUnion(arr1,arr2);
    printIntersection(arr1,arr2);

}