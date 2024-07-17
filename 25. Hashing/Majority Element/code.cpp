#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void majorityEls(vector<int> arr, vector<int> &ans) {
    unordered_map<int, int> map;

    for(int i: arr) {
        if(map.count(i) != 0) {
            map[i] = map[i] + 1;
        } else {
            map[i] = 1;
        }
    }

    for(pair<int, int> p: map) {
        if(p.second > (arr.size()/3)) {
            ans.push_back(p.first);
        }
    } 
}

int main() {
    vector<int> v = {1,3,2,5,1,3,1,5,1};
    vector<int> ans;

    majorityEls(v, ans);

    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
}