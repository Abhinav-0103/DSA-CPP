#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    class Info {
        public:
            int number;
            int idx;

            Info(int number, int idx) {
                this->number = number;
                this->idx = idx;
            }

            Info() {};
    };

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<Info> q;
        int n = tickets.size();

        for(int i=0;i<n;i++) {
            q.push(Info(tickets[i], i));
        }

        int ans = 0;

        Info curr;

        while(!q.empty()) {
            curr = q.front();
            
            curr.number -= 1;
            ans += 1;

            if(curr.idx == k && curr.number == 0) {
                break;
            } else if(curr.number != 0) {
                q.push(curr);
            }

            q.pop();
        }

        return ans;    
    }
};

int main() {
    vector<int> tickets = {5,1,1,1};
    int  k = 0;

    Solution sol;

    int time = sol.timeRequiredToBuy(tickets, k);

    cout << "Time taken by " << k << " index: " << time << endl;
}