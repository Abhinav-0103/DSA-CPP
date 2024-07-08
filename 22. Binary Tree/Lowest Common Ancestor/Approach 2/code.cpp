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

Node* lca(Node* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1) {
        return root;
    }

    if(root->data == n2) {
        return root;
    }

    Node* leftVal = lca(root->left,n1,n2);
    Node* rightVal = lca(root->right,n1,n2);

    if(leftVal == NULL && rightVal == NULL) {
        return NULL;
    } else if(leftVal == NULL) {
        return rightVal;
    } else if(rightVal == NULL) {
        return leftVal;
    }

    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    Node* ans = lca(root, 4, 5);

    cout << "LCA: " << ans->data << endl;
}