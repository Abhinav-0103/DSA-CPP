#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void findNextSmaller(vector<int> arr, vector<int> &nextSmaller) {
    stack<int> s;
    int n = arr.size();
    nextSmaller[n-1] = n;
    s.push(n-1);

    for(int i=n-2;i>=0;i--) {
        int curr = arr[i];

        while(!s.empty() && curr <= arr[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nextSmaller[i] = n;
        } else {
            nextSmaller[i] = s.top();
        }

        s.push(i);
    }
}

void findPrevSmaller(vector<int> arr, vector<int> &prevSmaller) {
    stack<int> s;
    int n = arr.size();

    prevSmaller[0] = -1;
    s.push(0);

    for(int i=0;i<n;i++) {
        int curr = arr[i];

        while(!s.empty() && curr <= arr[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            prevSmaller[i] = -1;
        } else {
            prevSmaller[i] = s.top();
        }

        s.push(i);
    }
}

int maxAreaHist(vector<int> height) {
    int n = height.size();
    vector<int> nextSmaller(n,0);
    vector<int> prevSmaller(n,0);

    findNextSmaller(height, nextSmaller);
    findPrevSmaller(height,prevSmaller);

    int maxArea = -1;
    int currArea;
    for(int i=0;i<height.size();i++) {
        int h = height[i];
        int w = nextSmaller[i] - prevSmaller[i] - 1;
 
        currArea = h * w;

        maxArea = max(currArea,maxArea);
    }

    return maxArea;
}

int main() {
    vector<int> arr = {2,1,5,6,2,3};

    cout << "Max Area in Histogram: " << maxAreaHist(arr) << endl;
}