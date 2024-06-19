#include<iostream>
#include<climits>
using namespace std;

int trappeRainwater(int height[], int n) {
    int leftMax[100000], rightMax[100000];
    leftMax[0] = INT_MIN;
    rightMax[n-1] = INT_MIN;

    for(int i=1;i<n;i++) {
        leftMax[i] = max(leftMax[i-1], height[i-1]);
    }

    for(int i=n-2;i>=0;i--) {
        rightMax[i] = max(rightMax[i+1], height[i+1]);
    }

    int trappedWtr = 0;

    for(int i=1;i<n-1;i++) {
        int currWater = min(leftMax[i], rightMax[i]) - height[i];

        if(currWater > 0) {
            trappedWtr+=currWater;
        }
        // trappedWtr+=max((min(leftMax[i], rightMax[i]) - height[i]), 0);
    }

    return trappedWtr;
}

int main() {
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int n = 7;

    int trpWtr = trappeRainwater(height, n);
    cout << "Amount of Trapped Rainwater = " << trpWtr << endl;

    return 0;
}