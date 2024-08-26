#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MaxSegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int> &arr, int st, int end, int node) {
        if(st == end) {
            tree[node] = arr[st];
            return;
        }

        int mid = st + (end - st) / 2;

        buildTree(arr,st,mid,2*node+1);
        buildTree(arr,mid+1,end,2*node+2);

        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

    int rangeQueryUtil(int qi, int qj, int si, int sj, int node) {
        if(qi > sj || qj < si) {
            return INT_MAX;
        }

        if(si >= qi && sj <= qj) {
            return tree[node];
        }

        int mid = si + (sj - si) / 2;

        int leftMin = rangeQueryUtil(qi,qj,si,mid,2*node+1);
        int rightMin = rangeQueryUtil(qi,qj,mid+1,sj,2*node+2);

        return min(leftMin, rightMin);
    }

    void updateQueryUtil(int idx, int newVal, int st, int end, int node) {
        if(st == end) {
            tree[node] = newVal;
            return;
        }

        int mid = st + (end - st) / 2;

        if(idx >= st && idx <= mid) {
            updateQueryUtil(idx,newVal,st,mid,2*node+1);
        } else {
            updateQueryUtil(idx,newVal,mid+1,end,2*node+2);
        }

        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

    public :
        MaxSegmentTree(vector<int> &arr) {
            n = arr.size();
            tree.resize(4*n);

            buildTree(arr,0,n-1,0);
        }

        void print() {
            for(int i: tree) {
                cout << i << " ";
            }
            cout << endl;
        }

        int rangeQuery(int qi, int qj) {
            return rangeQueryUtil(qi,qj,0,n-1,0);
        }

        void updateQuery(int idx, int val) {
            updateQueryUtil(idx,val,0,n-1,0);
        }
};

int main() {
    vector<int> arr = {6,8,-1,2,17,1,3,2,4};

    MaxSegmentTree st(arr);
    st.print();

    cout << st.rangeQuery(1,3) << endl;
    st.updateQuery(1,18);
    st.print();
    return 0;
}