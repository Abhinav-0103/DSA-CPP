#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

int kthAncestor(Node* root, int n, int k) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = kthAncestor(root->left,n,k);

    if(leftDist != -1) {
        if(leftDist + 1 == k) {
            cout << k << "th Ancestor: " << root->data << endl;
        }

        return leftDist + 1;
    }

    int rightDist = kthAncestor(root->right,n,k);
    
    if(rightDist != -1) {
        if(rightDist + 1 == k) {
            cout << k << "th Ancestor: " << root->data << endl;
        }

        return rightDist + 1;
    }

    return -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    int ans = kthAncestor(root, 4, 3);
}