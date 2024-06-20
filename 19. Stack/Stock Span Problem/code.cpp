#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int arr[], int span[], int n) {
    span[0] = 1;

    stack<int> s;
    s.push(0);

    int curr;

    for(int i=1;i<n;i++) {
        curr = arr[i];

        while(!s.empty() && curr >= arr[s.top()]) {
            s.pop();
        }    

        if(s.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - s.top();
        }

        s.push(i);
    }
}

int main() {
    int arr[] = {100, 80, 60, 70, 60, 85, 100};
    const int n = sizeof(arr) / sizeof(int);

    cout << "n = " << n << endl;

    int span[n];

    stockSpan(arr,span,n);

    for(int i: span) {
        cout << i << " ";
    }
}