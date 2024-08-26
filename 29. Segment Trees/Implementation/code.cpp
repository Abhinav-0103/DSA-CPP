#include<iostream>
#include<vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int> &arr, int st, int end, int nodeIdx) {
        if(st == end) {
            tree[nodeIdx] = arr[st];
            return;
        }

        int mid = st + (end - st) / 2;

        buildTree(arr,st,mid,2*nodeIdx+1);
        buildTree(arr,mid+1,end,2*nodeIdx+2);

        tree[nodeIdx]  = tree[2*nodeIdx+1] + tree[2*nodeIdx+2];
    }

    int rangeQueryUtil(int qi, int qj, int si, int sj, int node) {
        if(qj < si || qi > sj) {
            return 0;
        }
        if(si >= qi && sj <= qj) {
            return tree[node];
        } 
    
        int mid = si + (sj - si) / 2;

        int left = rangeQueryUtil(qi,qj,si,mid,2*node+1);
        int right = rangeQueryUtil(qi,qj,mid+1,sj,2*node+2);
        
        return left + right;
    }

    void updateQueryUtil(int idx, int val, int st, int end, int node) {
        if(st == end) {
            tree[node] = val;
            return;
        }

        int mid = st + (end - st) / 2;

        if(idx >= st && idx <= mid) {
            updateQueryUtil(idx,val,st,mid,2*node+1);
        } else {
            updateQueryUtil(idx,val,mid+1,end,2*node+2);
        }

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    public :
        SegmentTree(vector<int> &arr) {
            n = arr.size();
            tree.resize(4*n);
            buildTree(arr,0,n-1,0);
        }

        void printTree() {
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
    vector<int> arr = {1,2,3,4,5,6,7,8};

    SegmentTree st(arr);
    st.printTree();
    
    int qi = 2;
    int qj = 5;

    cout << "Range Query between " << qi << " & " << qj << ": " << st.rangeQuery(qi,qj) << endl; 

    st.updateQuery(1,3);

    st.printTree();
    return 0;
}