#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};

int main() {
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;

    pq.push(make_pair("Aman", 65));
    pq.push(make_pair("Ram", 75));
    pq.push(make_pair("Shyam", 85));

    while(!pq.empty()) {
        cout << pq.top().first << ": " << pq.top().second << endl;
        pq.pop();
    }
}