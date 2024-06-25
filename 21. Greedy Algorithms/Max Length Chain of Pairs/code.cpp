#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int maxLenChain(vector<int> start, vector<int> end) {
    int n = start.size();
    vector<pair<int,int>> pairs(n, make_pair(0,0));

    for(int i=0;i<n;i++) {
        pairs[i].first = start[i];
        pairs[i].second = end[i];
    }

    sort(pairs.begin(), pairs.end(), compare);

    // for(int i=0;i<n;i++) {
    //     cout << "(" << pairs[i].first << "," << pairs[i].second << ")" << endl;
    // }

    int count = 1;
    int currEnd = pairs[0].second;
    cout << "(" << pairs[0].first << "," << pairs[0].second << ")" << endl;

    for(int i=1;i<n;i++) {
        if(currEnd <= pairs[i].first) {
            count++;
            currEnd = pairs[i].second;
            cout << "(" << pairs[i].first << "," << pairs[i].second << ")" << endl;
        }
    }

    return count;
}

int main() {
    vector<int> start = {5,39,5,27,50};
    vector<int> end = {24,60,28,40,90};
    int n = start.size();
    

    int maxLen = maxLenChain(start,end);

    cout << "Max Length Chain of Pairs: " << maxLen << endl;
}