#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void pairSum(vector<int> v, int target) {
    unordered_map<int,int> map;
    int currTarget = target;
    for(int i=0;i<v.size();i++) {
        currTarget = target - v[i];

        if(map.count(currTarget) != 0 ) {
            cout << "[" << map[currTarget] << "," << i << "]" << endl;
            break;
        }

        map[v[i]] = i;
    }
}

int main() {
    vector<int> vec = {1,2,7,11,15,5,9};
    int target = 20;

    pairSum(vec,target);
}