#include<iostream>
#include<vector>
using namespace std;

int findCount(int arr[], int si, int ei, int mid) {
    vector<int> temp;
    int count = 0;

    int i = si;
    int j = mid + 1;

    while((i <= mid) && (j <= ei)) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            count++;
        }
    }

    if(i <= mid) {
        count += (mid - i);
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    while(j <= ei) {
        temp.push_back(arr[j++]);
    }

    i = si;
    for(int idx=0;i<=ei;i++) {
        arr[i] = temp[idx];
        idx++;
    }

    return count;
}

int inversionCount(int arr[], int si, int ei) {
    if(si >= ei) {
        // cout << si << " to " << ei << " : " << 0 << endl;
        return 0;
    }

    int mid = (si + ei) / 2;

    int countLeft = inversionCount(arr,si,mid);
    int countRight = inversionCount(arr,mid+1,ei);

    int currCount = findCount(arr,si,ei,mid);

    // cout << "Left Half - " << si << " to " << mid << " : " << countLeft << endl;
    // cout << "Right Half - " << mid+1 << " to " << ei << " : " << countRight << endl;
    // cout << "Count between: " << currCount << endl;

    // cout << endl << endl;

    return countLeft + countRight + currCount;
}

int main() {
    int arr[] = {7,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(int);

    cout << "Inversion Count: " << inversionCount(arr,0,n-1) << endl;
}