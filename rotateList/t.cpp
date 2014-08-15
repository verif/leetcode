/*
   Given a list, rotate the list to the right by k places, where k is
   non-negative.

   For example:
   Given 1->2->3->4->5->NULL and k = 2,
   return 4->5->1->2->3->NULL.
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
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
     ListNode *rotateRight(ListNode *head, int k) {
         if (!head || !k) return head;

         ListNode *p = head;
         ListNode *q = head;
         int i;
         int len = 0;

         for (i = 0; q && i < k; i++) {
             len++;
             q = q->next;
         }
         if (!q) {
             k = k % len;
             return rotateRight(head, k);
         }
         
         while (q->next) {
             p = p->next;
             q = q->next;
         }

         ListNode *ret = p->next;
         p->next = NULL;
         q->next = head;

         return ret;
     }
};

int main()
{
    Solution s;
    ListNode *ret;

    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ret = s.rotateRight(&l4, 3);

    while (ret) {
        cout << ret->val << ",";
        ret = ret->next;
    }
    cout << endl;
}

