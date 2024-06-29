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

class Info {
    public :
        int height;
        int diam;

        Info(int h, int d) {
            height = h;
            diam = d;
        }
};

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftCount = height(root->left);
    int rightCount = height(root->right);

    return max(leftCount,rightCount) + 1;
}

Info diameter(Node* root) {
    if(root == NULL) {
        return Info(0,0);
    }

    Info leftDiam = diameter(root->left);
    Info rightDiam = diameter(root->right);

    int currDiam = leftDiam.height + rightDiam.height + 1;
    int currHeight = max(leftDiam.height, rightDiam.height) + 1;

    int maxDiam = max(currDiam, max(leftDiam.diam, rightDiam.diam));

    return Info(currHeight, maxDiam);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->left->left->left = new Node(8);
    root->left->right->right->right = new Node(9);
    Info diam = diameter(root);

    cout << "Diameter: " << diam.diam << endl;
}