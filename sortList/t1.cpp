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
    int getListLength(ListNode* head) {
        ListNode* p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        return len;
    }

    ListNode* mergeTwoSortedLists(ListNode* h1, int len1,ListNode* h2, int len2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (1) {
            if (!h1) {
                current->next = h2;
                break;
            }
            if (!h2) {
                current->next = h1;
                break;
            }
            if (h1->val < h2->val) {
                current->next = h1;
                h1 = h1->next;
            }
            else {
                current->next = h2;
                h2 = h2->next;
            }
            current = current->next;
        }

        return dummy->next;
    }

    ListNode* sortListRecursive(ListNode* head, int len)
    {
        if (len < 2) return head;
        int len1 = len/2;
        int len2 = len - len1;

        ListNode* p = head;
        ListNode* prev = NULL;
        for (int i = 0; i < len1; i++) {
            prev = p;
            p = p->next;
        }
        // break the list into two
        if (prev) prev->next = NULL;

        ListNode* h1 = sortListRecursive(head, len1);
        ListNode* h2 = sortListRecursive(p, len2);
        ListNode* ret = mergeTwoSortedLists(h1, len1, h2, len2);

        return ret;
    }
public:
    ListNode *sortList(ListNode *head) {
        int len = getListLength(head);
        head = sortListRecursive(head, len);
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

    ListNode* head = s.sortList(&n1);
    printList(head);
}

