#include<iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 6, 10, 12, 14};

    int n = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter key to be searched : ";
    cin >> key;

    bool keyFound = false;

    for(int i=0;i<n;i++) {
        if(arr[i] == key) {
            keyFound = true;
            break;
        }
    }

    if(keyFound) {
        cout << "The key was found" << endl;
    } else {
        cout << "The key was not found" << endl;
    }

    return 0;
}