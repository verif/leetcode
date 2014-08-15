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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode dummy(0);

        ListNode *cur = head;
        while (cur) {
            ListNode *p = dummy.next;
            ListNode *next = cur->next;
            ListNode *prev = &dummy;
            while (p && p->val < cur->val) {
                prev = p;
                p = p->next;
            }
            prev->next = cur;
            cur->next = p;
            cur = next;
        }   
        
        return dummy.next;
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

