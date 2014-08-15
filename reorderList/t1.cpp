/*
   Given a singly linked list L: L0->L1->...->Ln-1->Ln
   reorder it to: L0->Ln->L1->Ln-1...
   You must do this in-place without altering the nodes' values.
   For example,
   Given {1,2,3,4}, reorder it  to {1,4,2,3}
*/

/**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode(int x) : val(x), next(NULL) {}
   * };
*/

#include <iostream>
#include <assert.h>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

static void printList(ListNode* head)
{
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}

class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return ret;
    }
    void reorderList(ListNode *head) {
        if (!head) return;
        int len = 0;
        ListNode *p = head;
        while (p) {len++; p = p->next;}
        
        ListNode *h2 = head, *prev = NULL;
        for (int i = 0; i < (len+1)/2; i++) {
            prev = h2;
            h2 = h2->next;
        }
        if (!h2) return;
        prev->next = NULL;
        
        // reverse 'h2'
        h2 = reverseList(h2);
        
        // Merge head/h2
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        
        while (head && h2) {
            tail->next = head;
            head = head->next;
            tail->next->next = h2;
            h2 = h2->next;
            tail = tail->next->next;
        }
        
        tail->next = head;
        head = dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode n1(1);
    ListNode n2(3);
    ListNode n3(5);
    ListNode n4(6);
    ListNode n5(4);
    ListNode n6(2);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    s.reorderList(&n1);

    printList(&n1);
}

