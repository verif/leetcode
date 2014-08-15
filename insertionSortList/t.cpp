/**
  Sort a linked list in O(n log n) time using constant space complexity.
**/

/*
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
    if (!head) return;
    ListNode* p = head;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
}

class Solution {
public:
    ListNode *insertIntoSortedList(ListNode* head, ListNode* p)
    {
        if (!head || !p) return NULL;
        ListNode* prev = NULL;
        ListNode* next = head;

        while (next) {
            if (p->val <= next->val) break;
            prev = next;
            next = next->next;
        }

        if (!prev) { // insert at head
            p->next = head;
            head = p;
        }
        else { 
            assert(prev);
            prev->next = p;
            p->next = next;
        } 

        return head;
    }

    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode* p = head->next;
        ListNode* pnext = p->next;
        head->next = NULL; // 'next' of last element of sorted list is NULL

        while (p) {
            head = insertIntoSortedList(head, p);
            p = pnext;
            if (!p) break;
            pnext = p->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode n1(3);
    ListNode n2(-3);
    ListNode n3(33);
    ListNode n4(-4);
    ListNode n5(34);
    ListNode n6(39);
    ListNode n7(0);
    ListNode n8(17);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;

    ListNode* head = s.insertionSortList(&n1);
    printList(head);
}

