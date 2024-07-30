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

        void longestHelper(Node* root, string &ans, string temp) {
            for(pair<char, Node*> child : root->children) {
                if(child.second->eow) {
                    temp += child.first;

                    if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                        ans = temp;
                    }

                    longestHelper(child.second, ans, temp);
                    temp = temp.substr(0, temp.size() - 1);
                }
            }
        }

        string longestStringWithEow() {
            string ans = "";
            string temp = "";
            longestHelper(root, ans, temp);
            return ans;
        }
};

string longestString(vector<string> dict) {
    Trie trie;

    for(int i=0;i<dict.size();i++) {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEow();
}

int main() {
    vector<string> words = {"banana", "a", "ap", "app", "appl", "apple", "apply"};

    cout << longestString(words) << endl;
    return 0;
}