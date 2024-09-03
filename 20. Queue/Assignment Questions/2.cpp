#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(), gas.end(),0);
        int costSum = accumulate(cost.begin(), cost.end(),0);

        if(costSum > gasSum) {
            return -1;
        }

        int currGas = 0;
        int start = 0;
        int n = gas.size();

        for(int i=0;i<n;i++) {
            currGas += gas[i] - cost[i];

            if(currGas < 0) {
                currGas = 0;
                start = i + 1;
            }
        }

        return start;
    }
};

int main() {
    Solution sol;

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    int startPoint = sol.canCompleteCircuit(gas,cost);

    cout << "Starting Point: " << startPoint << endl;
}