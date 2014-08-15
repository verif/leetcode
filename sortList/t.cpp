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
        ListNode* head = h1;

        // Merge list 'h2' into list 'h1'
        ListNode* p2 = h2;
        ListNode* p2next = NULL;
        ListNode* next = h1;
        ListNode* prev = NULL;
        for (int i = 0; i < len2; i++) {
            p2next = p2->next;
            while (next) {
                if (p2->val < next->val) break;
                prev = next;
                next = next->next;
            }
            // Merge p2 between prev/next
            if (!next) { // append at the end
                assert(prev);
                prev->next = p2;
                break;
            }
            else if(!prev) { // insert at the head 
                head = p2;
                p2->next = next;
                prev = p2;
                next = p2->next;
            }
            else { 
                prev->next = p2;
                p2->next = next;
                prev = p2;
            }
            p2 = p2next;
        }

        return head;
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

