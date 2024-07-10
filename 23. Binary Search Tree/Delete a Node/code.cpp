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

Node* inorderSucc(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* delNode(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data < val) {
        root->right = delNode(root->right,val);
        return root;
    } else if(root->data > val) {
        root->left = delNode(root->left,val);
        return root;
    }

    if(root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    } else if(root->left == NULL || root->right == NULL) {
        return root->left == NULL ? root->right : root->left;
    }

    Node* IS = inorderSucc(root->right);
    
    root->data = IS->data;

    root->right = delNode(root->right, root->data);

    return root;
}

int main() {
    int arr[10] = {8,5,3,1,4,6,7,10,11,14};

    Node* root = buildBST(arr,10);

    inorder(root);

    root = delNode(root,5);
    cout << endl;

    inorder(root);

    return 0;
}