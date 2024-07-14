#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void printVec(vector<int> v) {
    for(int i: v) {
        cout << i << " ";
    }
    cout << endl;
}

void slidWinMax(vector<int> vec, int K) {
    priority_queue<pair<int,int>> pq; // arr[i], idx
    vector<int> ans;

    for(int i=0;i<K;i++) {
        pq.push(make_pair(vec[i], i));
    }

    ans.push_back(pq.top().first);

    for(int i=K;i<vec.size();i++) {
        while(!pq.empty() && pq.top().second <= i-K) {
            pq.pop();
        }

        pq.push(make_pair(vec[i],i));

        ans.push_back(pq.top().first);
    }

    printVec(ans);
}

int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int K = 3;

    vector<int> maxVal;

    slidWinMax(arr,K);
}