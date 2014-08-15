/*
   Given a linked list, return the node where the cycle begins. If there is no
   cycle, return null.
   Follow up:
   Can you solve it without using extra space?
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
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
     ListNode *detectCycle(ListNode *head) {
         if (!head) return NULL;
         if (!head->next) return NULL;

         ListNode* p = head;
         ListNode* q = head;

         int len = 0;
         while (p) {
             len++;
             p = p->next;
             q = q->next;
             if (q) q = q->next;
             if (!p || !q) return NULL;
             if(p == q) break; // loop found
         }

         p = head;
         while (p != q) {
             p = p->next;
             q = q->next;
         }

         return p;
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
    ListNode n6(6);
    ListNode n7(7);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n5;

    ret = s.detectCycle(&n1);
    if (!ret) {
        cout << "No cycle" << endl;
    }
    else {
        cout << "Cycle found at node " << ret->val << endl;
    }
}
