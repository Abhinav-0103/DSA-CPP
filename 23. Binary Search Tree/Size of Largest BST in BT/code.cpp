#include<iostream>
#include<vector>
#include<climits>
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

class Info {
    public :
        bool isBST;
        int min;
        int max;
        int size;

        Info(bool isBST, int min, int max, int size) {
            this->isBST = isBST;
            this->min = min;
            this->max = max;
            this->size = size;
        }
};

static int maxSize = -1;

Info* largestBST(Node* root) {
    if(root == NULL) {
        return new Info(true,INT_MAX,INT_MIN,0);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    bool currIsBST;
    int currMin = min(min(leftInfo->min, rightInfo->min), root->data);
    int currMax = max(max(leftInfo->max, rightInfo->max), root->data);
    int currSize = leftInfo->size + rightInfo->size + 1;

    if(leftInfo->isBST && rightInfo->isBST
        && root->data > leftInfo->max
        && root->data < rightInfo->min) {

            currIsBST = true;

            maxSize = max(currSize, maxSize);

            return new Info(currIsBST, currMin, currMax, currSize);
    }

    return new Info(false, currMin, currMax, currSize);
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(50);

    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    preorder(root);
    cout << endl;

    largestBST(root);

    cout << "Max Size: " << maxSize << endl;
}