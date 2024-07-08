#include<iostream>
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

Node* lca(Node* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1) {
        return root;
    }

    if(root->data == n2) {
        return root;
    }

    Node* leftVal = lca(root->left,n1,n2);
    Node* rightVal = lca(root->right,n1,n2);

    if(leftVal == NULL && rightVal == NULL) {
        return NULL;
    } else if(leftVal == NULL) {
        return rightVal;
    } else if(rightVal == NULL) {
        return leftVal;
    }

    return root;
}

int dist(Node* root , int n) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = dist(root->left, n);

    if(leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);

    if(rightDist != -1) {
        return rightDist + 1;
    }

    return -1;
}

int minDist(Node* root, int n1, int n2) {
    Node* curr_lca = lca(root,n1,n2);

    int dist1 = dist(curr_lca,n1);
    int dist2 = dist(curr_lca,n2);

    return dist1 + dist2;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    Node* ans = lca(root, 4, 5);

    cout << "LCA: " << ans->data << endl;

    int distance = dist(root,7);

    cout << "Distance: " << distance << endl;

    int minimumDis = minDist(root,4,8);

    cout << "Minimum Distance: " << minimumDis << endl;
}