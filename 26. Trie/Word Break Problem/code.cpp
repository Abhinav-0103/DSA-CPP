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

bool wordBreakUtil(Trie trie, string key) {
    if(key.length() == 0) {
        return true;
    }

    for(int i=0;i<key.length();i++) {
        string first = key.substr(0,i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && wordBreakUtil(trie,second)) {
            cout << first << " + ";
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string> dict, string key) {
    Trie t;

    for(string s: dict) {
        t.insert(s);
    }

    return wordBreakUtil(t, key);
}

int main() {
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};

    cout << wordBreak(dict, "ilikesamsung") << endl;
    
    return 0;
}