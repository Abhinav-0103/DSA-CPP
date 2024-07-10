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

void printVec(vector<int> vec) {
    for(int i: vec) {
        cout << i << " ";
    }

    cout << endl;
}

void getInorderSeq(Node* root, vector<int> &seq) {
    if(root == NULL) {
        return;
    }

    getInorderSeq(root->left,seq);
    seq.push_back(root->data);
    getInorderSeq(root->right,seq);
}

void merge(vector<int> seq1, vector<int> seq2, vector<int> & sorted) {
    int i = 0;
    int j = 0;

    while(i < seq1.size() && j < seq2.size()) {
        if(seq1[i] <= seq2[j]) {
            sorted.push_back(seq1[i]);
            i++;
        } else {
            sorted.push_back(seq2[j]);
            j++;
        }
    }

    while(i < seq1.size()) {
        sorted.push_back(seq1[i]);
        i++;
    }

    while(j < seq2.size()) {
        sorted.push_back(seq2[j]);
        j++;
    }
}

Node* sortedToBalBST(vector<int> arr, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = (st + end) / 2;

    Node* curr = new Node(arr[mid]);

    curr->left = sortedToBalBST(arr,st,mid-1);
    curr->right = sortedToBalBST(arr,mid+1,end);

    return curr;
}

Node* mergeBST(Node* root1, Node* root2) {
    vector<int> seq1;
    vector<int> seq2;

    getInorderSeq(root1,seq1);
    getInorderSeq(root2,seq2);

    // printVec(seq1);
    // printVec(seq2);

    vector<int> sorted;

    merge(seq1,seq2,sorted);

    // printVec(sorted);

    return sortedToBalBST(sorted,0,sorted.size()-1);
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
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBST(root1,root2);

    vector<int> seq;

    getInorderSeq(root,seq);
    printVec(seq);
    preOrder(root);
}