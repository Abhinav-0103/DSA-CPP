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

bool search(Node* root1, Node* root2, int k) {
    if(root1 == NULL) {
        return false;
    }

    Node* c = root1;

    bool flag = false;

    while(c != NULL && flag != true) {
        if(c->data == k && root2 != c) {
            cout << "(" << root2->data << "," << c->data << ")" << endl;
            flag = true;
            return true;
        } else if(c->data < k) {
            c = c->right;
        } else {
            c = c->left;
        }
    }

    return false;
}

bool isPairPresent(Node* root1, Node* root2, int k) {
    if(root2 == NULL) {
        return false;
    }

    return search(root1, root2, k - root2->data) || isPairPresent(root1,root2->left,k) || isPairPresent(root1,root2->right,k);
}

int main() {
    int arr1[7] = {5,3,2,4,7,6,8};
    int arr2[7] = {10,6,3,8,15,12,18};

    Node* root1 = buildBST(arr1,7);
    Node* root2 = buildBST(arr2,7);

    int k = 16;

    if(isPairPresent(root1,root2,k)) {
        cout << "These are the pairs that we found" << endl;
    } else {
        cout << "No pairs found" << endl;
    }

    return 0;
}