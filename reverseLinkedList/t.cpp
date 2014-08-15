/*
   Reverse a linked list from position m to n. Do it in-place and in one-pass.
   For example:
   Given 1->2->3->4->5->NULL, m = 2 and n = 4,
   return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list
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
     ListNode *reverseBetween(ListNode *head, int m, int n) {
         if (!head) return NULL;
         if (m == n) return head;

         int k;
         ListNode *p = head;
         ListNode *q, *start;
         ListNode *prev, *next;
         prev = NULL; next = NULL;
         for (k = 1; k < m; k++) {
             prev = p;
             p = p->next;
         }
         q = p; start = p;
         for (k = 0; k < n-m; k++) {
             q = q->next;
         }
         next = q->next;

         // reverse the list between p & q
         ListNode* pprev = p;
         ListNode* pnext = NULL;
         p = p->next;
         while (p != next) {
             pnext = p->next; 
             p->next = pprev;
             pprev = p;
             p = pnext;
         }

         if (prev) prev->next = q;
         start->next = next;

         return prev ? head : q;
     }
};

int main()
{
    Solution s;
    ListNode* ret;

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ret = s.reverseBetween(&n1, 2, 4);

    while (ret) {
        cout << ret->val << "->";
        ret = ret->next;
    }
    cout << endl;
}

