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

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int hLeft = height(root->left);
    int hRight = height(root->right);

    return max(hLeft,hRight) + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int h = height(root);

    cout << "Height: " << h << endl;
}