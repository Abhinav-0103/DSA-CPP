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

void kthLevel(Node* root, int k, int currLevel) {
    if(root == NULL) {
        return;
    }

    if(k == currLevel) {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k, currLevel+1);
    kthLevel(root->right, k, currLevel+1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    kthLevel(root, 3, 1);
}