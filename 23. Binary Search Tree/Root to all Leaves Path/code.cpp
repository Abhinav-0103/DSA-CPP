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

void printPath(vector<int> path) {
    for(int i: path) {
        cout << i << " ";
    }

    cout << endl;
}

void rootToLeafPath(Node* root, vector<int> path) {
    if(root == NULL) {
        return;
    }

    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL) {
        printPath(path);
        path.pop_back();
        return;
    }

    rootToLeafPath(root->left, path);
    rootToLeafPath(root->right, path);

    path.pop_back();
}

int main() {
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    vector<int> path;
    rootToLeafPath(root,path);

    return 0;
}