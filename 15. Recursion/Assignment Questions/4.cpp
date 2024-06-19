#include<iostream>
using namespace std;

void towerOfHanoi(int n, char src, char helper, char dest) {
    if(n == 0) {
        return;
    }

    towerOfHanoi(n-1, src,dest,helper);
    cout << src << " --> " << dest << endl;
    towerOfHanoi(n-1, helper,src,dest);
}

int main() {
    int n = 3;

    towerOfHanoi(n,'A','B','C');
}