#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
    public :
        string key;
        int val;
        Node* next;

        Node(string key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
        }

        ~Node() {
            if(next != NULL) {
                delete next;
            }
        }
};

class HashTable {
    int totSize;
    int currSize;

    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        for(char c: key) {
            int val = c;
            idx = idx + (val * val) % totSize;
        }

        return idx % totSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = totSize * 2;
        currSize = 0;
        table = new Node*[totSize];

        for(int i=0;i<totSize;i++) {
            table[i] = NULL;
        }

        for(int i=0;i<oldSize;i++) {
            Node* temp = oldTable[i];

            while(temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next; 
            }
            
            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

    public :
        HashTable(int size=5) {
            totSize = size;
            currSize = 0;
            table = new Node*[totSize];

            for(int i=0;i<totSize;i++) {
                table[i] = NULL;
            }
        }

        void insert(string key, int val) {
            int idx = hashFunction(key);
            
            Node* newNode = new Node(key, val);

            newNode->next = table[idx];
            table[idx] = newNode;

            currSize++;

            double lambda = currSize / (double)totSize;

            if(lambda > 1) {
                rehash();
            }
        }

        bool exists(string key) {
            int idx = hashFunction(key);

            Node* temp = table[idx];

            while(temp != NULL) {
                if(temp->key == key) {
                    return true;
                }
                temp = temp->next;
            }

            return false;
        }

        int search(string key) {
            int idx = hashFunction(key);

            Node* temp = table[idx];

            while(temp != NULL) {
                if(temp->key == key) {
                    return temp->val;
                }
                temp = temp->next;
            }

            return -1;
        }

        void remove(string key) {
            int idx = hashFunction(key);

            Node* temp = table[idx];
            Node* prev = temp;

            while(temp != NULL) {
                if(temp->key == key) {
                    if(prev != temp) {
                        prev->next = temp->next;
                        temp->next = NULL;
                        delete temp;
                        break;
                    } else {
                        table[idx] = temp->next;
                        temp->next = NULL;
                        delete temp;
                    }
                }

                prev = temp;
                temp = temp->next;
            }
        }

        void print() {
            for(int i=0;i<totSize;i++) {
                cout << "idx" << i << "->" << endl;
                Node* temp = table[i];

                while(temp != NULL) {
                    cout << temp->key << " -> " << temp->val << endl;
                    temp = temp->next;
                }

                cout << endl;
            }
        }
};

int main() {
    HashTable ht;
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);

    if(ht.exists("India")) {
        int pop = ht.search("India");
        cout << "Indian Population: " << pop << endl;
    }

    ht.print();

    ht.remove("Nepal");

    ht.print();
    return 0;
}