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
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    Trie t;

    for(string s: words) {
        t.insert(s);
    }

    for(string s: words) {
        if(t.search(s)) {
            cout << s << " was found in Trie" << endl;
        } else {
            cout << s << " was not found in Trie" << endl;
        }
    }

    string temp = "theirs";
    if(t.search(temp)) {
        cout << temp << " was found in Trie" << endl;
    } else {
        cout << temp << " was not found in Trie" << endl;
    }
    return 0;
}