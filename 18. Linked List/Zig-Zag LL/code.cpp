#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

class List {
    public :
        Node* head;
        Node* tail;

        List() {
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
            head = newNode;

        }

        void push_back(int val) {
            Node* newNode = new Node(val);

            if(head == NULL) {
                head = tail = newNode;
                return;
            }

            tail->next = newNode;
            tail = newNode;
        }

        void pop_front() {
            if(head == NULL) {
                cout << "The List is Empty" << endl;
                return;
            }

            Node* temp = head;

            head = head->next;

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

            delete delNode;
            tail = temp;
        }

        void print() {
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
};

void printList(Node* head) {
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

Node* splitAtMid(Node* h) {
    Node* slow = h;
    Node* fast = slow;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL;
    }

    return slow;
}

Node* reverse(Node* h) {
    if(h == NULL || h->next == NULL) {
        return h;
    }

    Node* prev = NULL;
    Node* curr = h;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* zigZag(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* rightHeadRev = reverse(rightHead);

    cout << "\nFirst Half:  ";
    printList(head);

    cout << "\nSecond Half:  ";
    printList(rightHeadRev);

    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = NULL;

    while(left != NULL && right != NULL) {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        tail = right;
        left->next = right;
        right->next = nextLeft;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL) {
        tail->next = right;
    }

    return head;
}

int main() {
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);

    ll.print();

    ll.head = zigZag(ll.head);

    cout << "\nFinal:  ";
    ll.print();

    return 0;
}