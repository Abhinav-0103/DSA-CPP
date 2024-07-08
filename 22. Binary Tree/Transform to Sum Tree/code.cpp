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

int transformToSum(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = transformToSum(root->left);
    int rightSum = transformToSum(root->right);

    int currSum = leftSum + rightSum + root->data;

    root->data = leftSum + rightSum;

    return currSum;
}

void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(7);
    root->right->right = new Node(6);

    preOrder(root);
    cout << endl;
    transformToSum(root);
    preOrder(root);

}