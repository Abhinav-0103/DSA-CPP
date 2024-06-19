#include<iostream>
#include<string>
#include<vector>
using namespace std;

void merge(string str[], int si, int ei, int mid) {
    vector<string> temp;

    int i = si;
    int j = mid+1;

    while((i <= mid) && (j <= ei)) {
        if(str[i].compare(str[j]) < 0) {
            temp.push_back(str[i]);
            i++;
        } else {
            temp.push_back(str[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(str[i++]);
    }

    while(j <= ei) {
        temp.push_back(str[j++]);
    }

    i = si;
    for(int idx=0;i<=ei;i++) {
        str[i] = temp[idx];
        idx++;
    }
}

void mergeSort(string str[], int si, int ei) {
    if(si >= ei) {
        return;
    }

    int mid = (si + ei) / 2;

    mergeSort(str,si,mid);
    mergeSort(str,mid+1,ei);

    merge(str,si,ei,mid);
}

void printArray(string str[], int n) {
    for(int i=0;i<n;i++) {
        cout << str[i] << " ";
    }

    cout << endl;
}

int main() {
    string str[] = {"sun","earth","mars","mercury"};
    int n = 4;
    cout << "Before Sorting - " << endl;
    printArray(str,n);
    mergeSort(str,0,n-1);
    cout << "After Sorting - " << endl;
    printArray(str,n);
}