#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Node {
    public: 
        int val;
        Node* left;
        Node* right;

        Node(int val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
};

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    preorder(root->left);
    cout << root->val << " ";
    preorder(root->right);
}

Node* insert(Node* root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(root->val <= val) {
        root->right = insert(root->right,val);
    } else {
        root->left = insert(root->left,val);
    }

    return root;
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;
    for(int i: arr) {
        root = insert(root,i);
    }

    return root;
}

class Info {
    public:
        Node* root;
        int dist;

        Info(Node* root, int dist) {
            this->root = root;
            this->dist = dist;
        }
};

void bottomView(Node* root) {
    queue<Info> q;
    unordered_map<int, Node*> map;
    q.push(Info(root,0));
    int horDist = 0;
    map[horDist] = root;

    while(!q.empty()) {
        Info curr = q.front();
        q.pop();

        if(curr.root->left != NULL) {
            q.push(Info(curr.root->left,curr.dist-1));
            map[curr.dist-1] = curr.root->left;
        }

        if(curr.root->right != NULL) {
            q.push(Info(curr.root->right,curr.dist+1));
            map[curr.dist+1] = curr.root->right;
        }
    }

    for(auto it: map) {
        cout << it.first << "->" << it.second->val << endl;
    }
}

int main() {
    vector<int> arr = {20, 8, 5, 12, 10, 14, 22, 25};

    Node* root = buildBST(arr);

    bottomView(root);
}