/*
   Given a linked list, swap every two adjacent nodes and return its head.



   For example,

   Given 1->2->3->4, you should return the list as 2->1->4->3.



   Your algorithm should use only constant space. You may not modify the values
   in the list, only nodes itself can be changed.
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

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
     ListNode *swapPairs(ListNode *head) {
         int k = 2;
         if (!head) return head;
         ListNode* prevTail = NULL;
         ListNode* curHead = head;
         ListNode* tail = head;
         ListNode *last = NULL;
         ListNode *next = head;
         while (tail) {
             int i;
             for (i = 0; tail && i < k; i++) {
                 next = tail->next;
                 tail->next = last;
                 last = tail;
                 tail = next;
             }
             if (!tail && i < k) { // Need to restore if remaining < k items
                 tail = last;
                 last = NULL;
                 while (last != curHead) {
                     next = tail->next;
                     tail->next = last;
                     last = tail;
                     tail = next;
                 }
                 break;
             }
             if (prevTail) {
                 prevTail->next = last;
             }
             else {
                 head = last;
             }
             prevTail = curHead;
             curHead->next = tail;
             curHead = tail;
         }

         return head;
     }
};

int main()
{
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode* ret;
    ListNode* head;

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ret = head = s.swapPairs(&l1);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.swapPairs(head);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.swapPairs(head);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.swapPairs(head);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.swapPairs(head);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;
}
