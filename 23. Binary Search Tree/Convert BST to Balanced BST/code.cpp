#include<iostream>
#include<vector>
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

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

void getSortedSeq(Node* root, vector<int> &seq) {
    if(root == NULL) {
        return;
    }

    getSortedSeq(root->left,seq);
    seq.push_back(root->data);
    getSortedSeq(root->right,seq);
}

Node* sortedToBalancedBST(vector<int> seq, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = (st + end) / 2;

    Node* currNode = new Node(seq[mid]);

    currNode->left = sortedToBalancedBST(seq,st,mid-1);
    currNode->right = sortedToBalancedBST(seq,mid+1,end);

    return currNode;
}

Node* convertToBalancedBST(Node* root) {
    vector<int> seq;
    getSortedSeq(root,seq);

    root = sortedToBalancedBST(seq,0,seq.size()-1);

    return root;
}

int main() {
    int arr[7] = {6,5,4,3,7,8,9};

    Node* root = buildBST(arr,7);

    preorder(root);
    cout << endl;

    root = convertToBalancedBST(root);
    preorder(root);

    return 0;
}