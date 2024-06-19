#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> vec;

    int x = 1;

    for(int i=0;i<3;i++) {
        vector<int> temp;
        for(int j=0;j<3;j++) {
            temp.push_back(x);
            x++;
        }
        vec.push_back(temp);
    }

    for(int i=0;i<vec.size();i++) {
        for(int j=0;j<vec[0].size();j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}