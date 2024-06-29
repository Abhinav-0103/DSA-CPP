#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<pair<Node*,int>> q;
    map<int,int> map;
    q.push(make_pair(root,0));

    while(!q.empty()) {
        pair<Node*, int> currNode = q.front();
        q.pop();

        if(map.count(currNode.second) == 0) {
            map[currNode.second] = currNode.first->data;
        }

        if(currNode.first->left != NULL) {
            q.push(make_pair(currNode.first->left, currNode.second-1));
        }

        if(currNode.first->right != NULL) {
            q.push(make_pair(currNode.first->right, currNode.second+1));
        }
    }

    for(auto it: map) {
        cout << it.second << " ";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    topView(root);
}