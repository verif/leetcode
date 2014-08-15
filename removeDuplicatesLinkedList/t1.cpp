/*
   Given a sorted linked list, delete all nodes that have duplicate numbers,
   leaving only distinct numbers from the original list.

   For example,
   Given 1->2->3->3->4->4->5, return 1->2->5.
   Given 1->1->1->2->3, return 2->3.
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
     ListNode *deleteDuplicates(ListNode *head) {
         if (!head) return NULL;
         ListNode* prev = NULL;
         ListNode* p = head;
         int lastVal = p->val-1;

         while (p) {
             if (p->val == lastVal) {
                 if (!prev) {
                     head = p = p->next;
                 }
                 else {
                     prev->next = p = p->next;
                 }
             }
             else {
                lastVal = p->val;
                prev = p;
                p = p->next;
             }
         }

         return head;
     }
};

int main()
{
    Solution s;
    ListNode* ret;

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(4);
    ListNode n7(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    ret = s.deleteDuplicates(&n1);
    while (ret) {
        cout << ret->val << ",";
        ret = ret->next;
    }
    cout << endl;

    ListNode n8(1);
    ListNode n9(1);
    ListNode n10(1);
    ListNode n11(2);
    ListNode n12(3);

    n8.next = &n9;
    n9.next = &n10;
    n10.next = &n11;
    n11.next = &n12;

    ret = s.deleteDuplicates(&n8);
    while (ret) {
        cout << ret->val << ",";
        ret = ret->next;
    }
    cout << endl;
}
