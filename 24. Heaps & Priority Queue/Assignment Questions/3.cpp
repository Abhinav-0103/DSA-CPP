#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for(char ch: tasks) {
            freq[ch - 'A']++;
        }

        sort(begin(freq), end(freq));

        int chunks = freq[25] - 1;
        int idleSpaces = chunks * n;

        for(int i=24;i>=0;i--) {
            if(freq[i] == 0) {
                break;
            }

            idleSpaces -= min(chunks, freq[i]);
        }

        return idleSpaces <= 0 ? tasks.size() : tasks.size() + idleSpaces;
    }
};

int main() {
    Solution sol;

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << "Answer: " << sol.leastInterval(tasks, n) << endl;
}