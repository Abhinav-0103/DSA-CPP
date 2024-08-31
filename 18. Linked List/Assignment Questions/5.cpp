// LeetCode 23
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(head1 == NULL && head2 == NULL) {
            return NULL;
        } else if(head1 == NULL) {
            return head2;
        } else if(head2 == NULL) {
            return head1;
        }
        ListNode* newHead;

        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* prev = head1;

        if(head1->val <= head2->val) {
            newHead = head1;
            prev = temp1;
            temp1 = temp1->next;
        } else {
            newHead = head2;
            prev = temp2;
            temp2 = temp2->next;
        }

        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val <= temp2->val) {
                prev->next = temp1;
                prev = temp1;
                temp1 = temp1->next;
            } else {
                prev->next = temp2;
                prev = temp2;
                temp2 = temp2->next;
            }
        }

        if(temp2 == NULL) {
            prev->next = temp1;
        }

        if(temp1 == NULL) {
            prev->next = temp2;
        }

        return newHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }

        if(lists.size() == 1) {
            return lists[0];
        }

        ListNode* head = lists[0];

        for(int i=1;i<lists.size();i++) {
            head = merge(head, lists[i]);
        }

        return head;
    }
};