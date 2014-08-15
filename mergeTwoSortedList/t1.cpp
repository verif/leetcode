/*
   Merge two sorted linked lists and return it as a new list. The new list
   should be made by splicing together the nodes of the first two lists.
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
     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
         ListNode *dummy = new ListNode(0);
         ListNode *current = dummy;

         while (1) {
             if (!l1) {
                 current->next = l2;
                 break;
             }
             if (!l2) {
                 current->next = l1;
                 break;
             }
             if (l1->val < l2->val) {
                 current->next = l1;
                 l1 = l1->next;
             }
             else {
                 current->next = l2;
                 l2 = l2->next;
             }
             current = current->next;
         }

         return dummy->next;
     }
};

int main()
{
    Solution s;
    ListNode* ret;

    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);

    l1.next = &l3;
    l3.next = &l5;
    l2.next = &l4;
    l4.next = &l6;

    ret = s.mergeTwoLists(&l1, &l2);
    while (ret) {
        cout << ret->val << ",";
        ret = ret->next;
    } 
    cout << endl;
}
