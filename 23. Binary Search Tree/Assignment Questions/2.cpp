#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
};

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* insert(Node* root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(root->data < val) {
        root->right = insert(root->right,val);
    } else {
        root->left = insert(root->left,val);
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0;i<n;i++) {
        root = insert(root,arr[i]);
    }

    return root;
} 

void minAbsUtil(Node* root, int k, int min, int max, int &ans) {
    if(root == NULL) {
        return;
    }

    if(root->data < min || root->data > max) {
        return; 
    }

    int diff = abs(root->data - k);

    if(diff < abs(ans - k)) {
        ans = root->data;
    }

    minAbsUtil(root->left,k,k-diff,k+diff,ans);
    minAbsUtil(root->right,k,k-diff,k+diff,ans);
}

int minAbsDiff(Node* root, int k) {
    int ans = 0;
    minAbsUtil(root,k,INT_MIN,INT_MAX,ans);

    return ans;
}

int main() {
    int arr[6] = {8,5,3,6,11,20};

    Node* root = buildBST(arr,6);

    inorder(root);
    cout << endl;

    int k = 19;

    int minDiff = minAbsDiff(root,k);

    cout << "Min DIff: " << minDiff << endl;

    return 0;
}