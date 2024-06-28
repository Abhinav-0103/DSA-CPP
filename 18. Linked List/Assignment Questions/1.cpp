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
};

void printLL(LL ll) {
    while(ll.head != NULL) {
        cout << ll.head->data << "->";
        ll.head = ll.head->next;
    }

    cout << endl;
}

Node* getIntersection(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    int n1 = 0;
    int n2 = 0;

    while(temp1 != NULL) {
        temp1 = temp1->next;
        n1++;
    }

    while(temp2 != NULL) {
        temp2 = temp2->next;
        n2++;
    }

    int diff = abs(n1 - n2);

    temp1 = head1;
    temp2 = head2;

    if(n1 > n2) {
        for(int i=0;i<diff;i++) {
            temp1 = temp1->next;
        }
    } else {
        for(int i=0;i<diff;i++) {
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
}

int main() {
    LL ll_1;
    LL ll_2;

    ll_1.push_back(1);
    ll_1.push_back(2);
    ll_1.push_back(3);
    ll_1.push_back(6);
    ll_1.push_back(7);

    ll_2.push_back(4);
    ll_2.push_back(5);

    ll_2.head->next->next = ll_1.head->next->next->next;

    printLL(ll_1);
    printLL(ll_2);

    Node* intersection = getIntersection(ll_2.head, ll_1.head);

    if(intersection == NULL) {
        cout << "NULL" << endl;
    } else {
        cout << "Intersection at: " << intersection->data << endl;
    }
}