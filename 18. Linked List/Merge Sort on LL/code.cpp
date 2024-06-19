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

Node* merge(Node* left, Node* right) {
    List ans;

    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* splitAtMid(Node* h) {
    Node* slow = h;
    Node* fast = slow;
    Node* prev = slow;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    return slow;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);
    
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left,right);
}

int main() {
    List ll;

    ll.push_back(4);
    ll.push_front(6);
    ll.push_back(5);
    ll.push_front(7);
    ll.push_front(1);
    ll.push_front(8);

    ll.print();

    ll.head = mergeSort(ll.head);

    ll.print();
    return 0;
}