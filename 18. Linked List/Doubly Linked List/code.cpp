#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

class DoublyList {
    public :
        Node* head;
        Node* tail;

        DoublyList() {
            head = NULL;
            tail = NULL;
        }
        
        void push_front(int val) {
            Node* newNode = new Node(val);
            // Node* newNode(val); Static Allocation -> Deleted after function termination

            if(head == NULL) {
                head = tail = newNode;
                return;
            }

            newNode->next = head;
            head->prev = newNode;
            head = newNode;

        }

        void push_back(int val) {
            Node* newNode = new Node(val);

            if(head == NULL) {
                head = tail = newNode;
                return;
            }

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void pop_front() {
            if(head == NULL) {
                cout << "The List is Empty" << endl;
                return;
            }

            Node* temp = head;

            head = head->next;
            head->prev = NULL;

            temp->next = NULL;
            delete temp;
        }

        void pop_back() {
            if(head == NULL) {
                cout << "The List is Empty" << endl;
                return;
            }

            if(head->next == NULL) {
                delete head;
                return;
            }

            Node* temp = head;

            while(temp->next->next != NULL) {
                temp = temp->next;
            }

            Node* delNode = temp->next;
            temp->next = NULL;
            delNode->prev = NULL;

            delete delNode;
            tail = temp;
        }

        void printFront() {
            if(head == NULL) {
                cout << "NULL" << endl;
                return;
            }

            Node* temp = head;

            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }

        void printReverse() {
            if(head == NULL) {
                cout << "NULL" << endl;
                return;
            }

            Node* temp = tail;

            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->prev;
            }

            cout << "NULL" << endl;
        }
};

int main() {
    DoublyList ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);

    ll.printFront();
    ll.printReverse();

    ll.pop_front();
    ll.pop_back();

    ll.printFront();
    ll.printReverse();

    return 0;
}