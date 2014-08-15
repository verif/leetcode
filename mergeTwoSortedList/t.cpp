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
         if (!l1) return l2;
         if (!l2) return l1;

         ListNode *ret = l1;
         ListNode *p = l1; 
         ListNode *q = l2;

         ListNode* prev = NULL;
         ListNode* next = NULL;
         while (p && q) {
             while (p && p->val < q->val) {
                 prev = p;
                 p = p->next;
             }
             if (!p) break;
             if (prev) prev->next = q;
             else ret = q;

             next = q->next;
             q->next = p;

             prev = q;
             q = next;
         }

         if (q) {
             prev->next = q;
         }

         return ret;
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
