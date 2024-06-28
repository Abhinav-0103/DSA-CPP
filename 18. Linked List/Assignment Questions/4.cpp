#include<iostream>
#include<vector>
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

Node* oddEven(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* temp = head;
    Node* evenStart = NULL;
    Node* oddStart = NULL;
    Node* evenTrack = NULL;
    Node* oddTrack = NULL;

    while(temp != NULL) {
        if(temp->data % 2 == 0) {
            if(evenStart == NULL) {
                evenStart = temp;
                evenTrack = temp;
            } else {
                evenTrack->next = temp;
                evenTrack = temp;
            }
        } else {
            if(oddStart == NULL) {
                oddStart = temp;
                oddTrack = temp;
            } else {
                oddTrack->next = temp;
                oddTrack = temp;
            }
        }

        temp = temp->next;
    }

    if(evenTrack != NULL) {
        evenTrack->next = oddStart;
    }

    if(oddTrack != NULL) {
        oddTrack->next = NULL;
    }

    if(evenStart != NULL) {
        head = evenStart;
    } else {
        head = oddStart;
    }

    return head;
 }

int main() {
    LL ll;

    vector<int> values = {1,2,4,6,8};

    for(int i=0;i<values.size();i++) {
        ll.push_back(values[i]);
    }

    printLL(ll.head);

    ll.head = oddEven(ll.head);

    printLL(ll.head);
}