#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int countDistinct(vector<int> arr) {
    unordered_set<int> s;
    for(int i: arr) {
        if(s.find(i) == s.end()) {
            s.insert(i);
        }
    }

    return s.size();
}

int main() {
    vector<int> arr = {4,3,2,5,6,7,3,4,2,1};

    int count = countDistinct(arr);

    cout << count << " distinct elements" << endl;
}