#include<iostream>
#include<vector>
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

static int idx = -1;

Node* buildTree(vector<int> nodes) {
    idx++;

    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(nodes[idx]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

void preorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    preorderTraversal(root);

    cout << endl << idx << endl;
}