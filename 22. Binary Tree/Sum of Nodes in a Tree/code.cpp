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

int sumNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftCount = sumNodes(root->left);
    int rightCount =sumNodes(root->right);

    return leftCount + rightCount + root->data;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    int total = sumNodes(root);

    cout << "Sum of Nodes: " << total << endl;
}