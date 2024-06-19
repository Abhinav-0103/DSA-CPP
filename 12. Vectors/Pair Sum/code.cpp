#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> vec, int target) {
    vector<int> ans;
    int start = 0;
    int end = vec.size() - 1;

    while(start < end) {
        int currSum = vec[start] + vec[end];

        if(currSum == target) {
            ans.push_back(start);
            ans.push_back(end);
            break;
        } else if(currSum > target) {
            end--;
        } else {
            start++;
        }
    }

    return ans;
}

int main() {
    vector<int> vec = {2,7,11,15};
    int target = 13;

    vector<int> ans = pairSum(vec, target);

    cout << "The pair is present at indices " << ans[0] << " & " << ans[1] << endl;
}