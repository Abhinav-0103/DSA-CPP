#include<iostream>
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

        void push_back(int val) {
            Node* newNode = new Node(val);

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

        void swap(int n, int m) {
            if(head == NULL) {
                return;
            }

            Node* temp1 = head;
            Node* prev1 = NULL;
            Node* next1 = temp1->next;

            for(int i=0;i<n;i++) {
                prev1 = temp1;
                temp1 = temp1->next;
                next1 = temp1->next;
            }

            Node* temp2 = head;
            Node* prev2 = NULL;
            Node* next2 = temp1->next;

            for(int i=0;i<m;i++) {
                prev2 = temp2;
                temp2 = temp2->next;
                next2 = temp2->next;
            }

            prev1->next = temp2;
            temp2->next = next1;

            prev2->next = temp1;
            temp1->next = next2;
        }
};

void printLL(LL ll) {
    while(ll.head != NULL) {
        cout << ll.head->data << "->";
        ll.head = ll.head->next;
    }

    cout << endl;
}


int main() {
    LL ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(6);
    ll.push_back(7);

    int n = 2;
    int m = 2;

    printLL(ll);

    ll.swap(1,3);

    printLL(ll);
}