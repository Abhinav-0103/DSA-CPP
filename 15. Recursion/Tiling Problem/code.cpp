#include<iostream>
using namespace std;

int tilingProblem(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    int ans1 = tilingProblem(n-1);
    int ans2 = tilingProblem(n-2);

    return ans1 + ans2;
}

int main() {
    cout << "No. of ways: " << tilingProblem(4) << endl;
}