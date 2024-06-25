#include<iostream>
#include<vector>
using namespace std;

int maxActivity(vector<int> start, vector<int> end) {
    int currEnd = end[0];
    int actCount = 1;
    cout << "A0 -> ";

    for(int i=1;i<start.size();i++) {
        if(currEnd <= start[i]) {
            actCount++;
            currEnd = end[i];
            cout << "A" << i << " -> ";
        }
    }
    
    cout << endl;

    return actCount;
}

int main() {
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    int activityCount = maxActivity(start, end);
    cout << "Max Activities: " << activityCount << endl;
}