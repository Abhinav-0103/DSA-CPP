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

        bool startsWith(string prefix) {
            int n = prefix.length();
            Node* temp = root;

            for(int i=0;i<n;i++) {
                if(temp->children.count(prefix[i]) == 0) {
                    return false;
                }

                temp = temp->children[prefix[i]];
            }

            return true;
        }
};

int main() {
    vector<string> words = {"apple", "app", "mango", "man", "woman"};

    Trie t;

    for(string s: words) {
        t.insert(s);
    }

    string prefix = "app";
    if(t.search(prefix)) {
        cout << prefix << " was found in Trie" << endl;
    } else {
        cout << prefix << " was not found in Trie" << endl;
    }
    return 0;
}