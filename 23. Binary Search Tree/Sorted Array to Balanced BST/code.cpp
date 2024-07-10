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

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

Node* buildBalBST(vector<int> arr, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = (st + end) / 2;

    Node* currNode = new Node(arr[mid]);

    currNode->left = buildBalBST(arr,st,mid-1);
    currNode->right = buildBalBST(arr,mid+1,end);

    return currNode;
}

int main() {
    vector<int> arr = {3,4,5,6,7,8,9};

    Node* root = buildBalBST(arr,0,arr.size()-1);

    preorder(root);

    cout << endl;
}