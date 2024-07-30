#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
    public :
        unordered_map<char, Node*> children;
        bool eow;

        Node() {
            eow = false;
        }
};

class Trie {
    Node* root;

    public :
        Trie() {
            root = new Node();
        }

        void insert(string key) {
            int n = key.length();
            Node* temp = root;

            for(int i=0;i<n;i++) {
                if(temp->children.count(key[i]) == 0) {
                    temp->children[key[i]] = new Node();
                }

                temp = temp->children[key[i]];
            }

            temp->eow = true;
        }

        bool search(string key) {
            int n = key.length();
            Node* temp = root;

            for(int i=0;i<n;i++) {
                if(temp->children.count(key[i]) == 0) {
                    return false;
                }

                temp = temp->children[key[i]];
            }

            if(temp->eow != true) {
                return false;
            }

            return true;
        }

        int countHelper(Node* root) {
            int ans = 0;

            for(pair<char, Node*> child : root->children) {
                ans+=countHelper(child.second);
            }

            return ans + 1;
        }

        int countNodes() {
            return countHelper(root);
        }
};

int countUniqueSubstr(string str) {
    Trie trie;

    for(int i=0;i<str.size();i++) {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main() {
    cout << countUniqueSubstr("ababa") << endl;
    return 0;
}