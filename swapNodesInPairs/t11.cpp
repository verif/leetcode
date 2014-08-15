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
        if (!head || !head->next) return head;
        
        ListNode *p = swapPairs(head->next->next);
        ListNode *ret = head->next;
        head->next->next = head;
        head->next = p;
        
        return ret;
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
