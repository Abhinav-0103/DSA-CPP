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

bool findPath(Node* root, int n, vector<int> &path) {
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);

    if(root->data == n) {
        return true;
    }

    bool leftTree = findPath(root->left,n,path);
    bool rightTree = findPath(root->right,n,path);

    if(!leftTree && !rightTree) {
        path.pop_back();
        return false;
    }

    return true;
}

void printPath(vector<int> path) {
    for(int i=0;i<path.size();i++) {
        cout << path[i] << " ";
    }

    cout << endl;
}

int lca(Node* root, int n1, int n2) {
    vector<int> path1;
    vector<int> path2;

    findPath(root,n1,path1);
    findPath(root,n2,path2);

    printPath(path1);
    printPath(path2);

    int ans;

    for(int i=0;i<path1.size() && i<path2.size();i++) {
        if(path1[i] == path2[i]) {
            ans = path1[i];
        }
    }

    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    int ans = lca(root, 4, 7);

    cout << "LCA: " << ans << endl;
}