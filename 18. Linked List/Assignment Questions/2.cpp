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

        void delNAfterM(int n, int m) {
            Node* temp1 = head;

            for(int i=0;i<m-1;i++) {
                temp1 = temp1->next;
            }

            Node* temp2 = temp1;

            for(int i=0;i<n;i++) {
                temp2 = temp2->next;
            }

            temp1->next = temp2->next;
            temp2->next = NULL;
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

    ll.delNAfterM(3,1);

    printLL(ll);
}