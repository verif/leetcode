/*
   Given a linked list, remove the nth node from the end of list and return its
   head.

   For example,
      Given linked list: 1->2->3->4->5, and n = 2.
         After removing the second node from the end, the linked list becomes
         1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <iostream>

/**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode(int x) : val(x), next(NULL) {}
   * };
*/

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
     ListNode *removeNthFromEnd(ListNode *head, int n) {
         if (!head) return head;
         ListNode *p1 = head;
         ListNode *p2 = p1;
         for (int i = 0; i < n; i++) {
             p1 = p1->next;
         }
         if (!p1) return head->next;
         while (p1->next) {
             p1 = p1->next;
             p2 = p2->next;
         }
         p2->next = p2->next->next;
         return head;
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

    ret = s.removeNthFromEnd(&l1, 2);

    while (ret) {
        std::cout << ret->val << ",";
        ret = ret->next;
    }
    std::cout << std::endl;
}

