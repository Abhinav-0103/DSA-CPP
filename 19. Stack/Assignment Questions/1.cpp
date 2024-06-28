#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node {
    public :
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class LL {
    public :
        Node* head;

        LL() {
            head = NULL;
        }

        void push_back(int data) {
            Node* newNode = new Node(data);

            if(head == NULL) {
                head = newNode;
                return;
            }

            Node* temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
};

void printLL(Node* head) {
    if(head == NULL) {
        return;
    }

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << endl;
}

bool isPalindrome(Node* head) {
    if(head == NULL || head->next == NULL) {
        return true;
    }

    stack<int> s;

    Node* temp = head;

    while(temp != NULL) {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL) {
        if(temp->data != s.top()) {
            return false;
        }

        s.pop();
        temp = temp->next;
    }

    return true;
}

int main() {
    LL ll;

    vector<int> values = {1,2,3,2,1};

    for(int i=0;i<values.size();i++) {
        ll.push_back(values[i]);
    }

    printLL(ll.head);

    bool isPalin = isPalindrome(ll.head);

    cout << isPalin << endl;
}