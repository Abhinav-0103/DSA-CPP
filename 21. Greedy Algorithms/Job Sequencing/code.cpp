#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
    return a.first.second > b.first.second;
}

int jobSequence(vector<pair<pair<int,int>,int>> jobs) {
    sort(jobs.begin(),jobs.end(),compare);

    int maxProfit = jobs[0].first.second;
    int safeDeadline = jobs[0].first.first + 1;
    cout << "Job " << jobs[0].second << ":" << jobs[0].second << endl;
    int n = jobs.size();

    for(int i=1;i<n;i++) {
        if(jobs[i].first.first >= safeDeadline) {
            maxProfit += jobs[i].first.second;
            safeDeadline = jobs[i].first.first + 1;
            cout << "Job " << jobs[i].second << ":" << jobs[i].first.second << endl;
        }
    }

    return maxProfit;
}

int main() {
    vector<int> deadline = {4,1,1,1};
    vector<int> profit = {20,10,40,30};
    int n = profit.size();

    vector<pair<pair<int,int>,int>> jobs(n, make_pair(make_pair(0,0),0));

    for(int i=0;i<n;i++) {
        jobs[i].first.first = deadline[i];
        jobs[i].first.second = profit[i];
        jobs[i].second = i;
    }

    int maxProfit = jobSequence(jobs);

    cout << "Max Profit: " << maxProfit << endl;
}