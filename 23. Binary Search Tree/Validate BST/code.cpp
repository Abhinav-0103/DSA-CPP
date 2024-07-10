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

bool validateBSTUtil(Node* root, Node* min , Node* max) {
    if(root == NULL) {
        return true;
    }

    if((min != NULL && root->data < min->data) || (max != NULL && root->data > max->data)) {
        return false;
    }

    return validateBSTUtil(root->left,min,root) && validateBSTUtil(root->right,root,max);
}

bool validateBST(Node* root) {
    return validateBSTUtil(root,NULL,NULL);
}

int main() {
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);
    // root->right->left = new Node(2);
    inorder(root);
    cout << endl;

    cout << "Is BST: " << validateBST(root) << endl;

    return 0;
}