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

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if(root1 == NULL || root2 == NULL) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubTree(Node* root, Node* subRoot) {
    if(root == NULL && subRoot == NULL) {
        return true;
    } else if(root == NULL || subRoot == NULL) {
        return false;
    }

    if(root->data == subRoot->data) {
        if(isIdentical(root, subRoot)) {
            return true;
        }
    }

    bool isLeftSub = isSubTree(root->left, subRoot);

    if(!isLeftSub) {
        return isSubTree(root->right, subRoot);
    }

    return true;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    bool isSubtree = isSubTree(root, subRoot);

    cout << "Is Sub Tree: " << isSubtree << endl; 
}