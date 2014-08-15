/*
   Given a linked list, reverse the nodes of a linked list k at a time and
   return its modified list.
   If the number of nodes is not a multiple of k then left-out nodes in the end
   should remain as it is.
   You may not alter the values in the nodes, only nodes itself may be changed.
   Only constant memory is allowed.

   For example,
   Given this linked list: 1->2->3->4->5
   For k = 2, you should return: 2->1->4->3->5
   For k = 3, you should return: 3->2->1->4->5
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
     ListNode *reverseKGroup(ListNode *head, int k) {
         if (!head || k < 2) return head;
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

    ret = head = s.reverseKGroup(&l1, 2);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.reverseKGroup(head, 3);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.reverseKGroup(head, 4);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.reverseKGroup(head, 5);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;

    ret = head = s.reverseKGroup(head, 6);
    while (ret) {
        std::cout << ret->val << "->";
        ret = ret->next;
    }
    std::cout << std::endl;
}
