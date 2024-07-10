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

bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    } else if(root->data < key) {
        return search(root->right,key);
    } else {
        return search(root->left,key);
    }
}

int main() {
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);

    inorder(root);
    cout << endl;

    int key = 4;
    cout << key << " found: " << search(root, key) << endl;

    return 0;
}