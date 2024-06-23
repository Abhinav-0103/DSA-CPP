#include<iostream>
#include<queue>
using namespace std;

void firstNonRepeat(string str) {
    queue<char> q;

    int freq[26] = {0};

    for(char ch: str) {
        freq[ch - 'a']++;

        q.push(ch);

        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if(q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
}

int main() {
    string str = "aabccxb";

    firstNonRepeat(str);
}