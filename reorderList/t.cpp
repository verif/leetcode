/*
   Given a singly linked list L: L0->L1->...->Ln-1->Ln
   reorder it to: L0->Ln->L1->Ln-1...
   You must do this in-place without altering the nodes' values.
   For example,
   Given {1,2,3,4}, reorder it  to {1,4,2,3}
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
#include <assert.h>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

static void printList(ListNode* head)
{
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}

class Solution {
public:
     void reorderList(ListNode *head) {
         if (!head || !head->next) return;
         // first get list length 
         int len = 0;
         ListNode* p = head;
         while (p) {
             len++;
             p = p->next;
         }

         // second, split the list into two 
         int len1 = (len+1)/2;
         int len2 = len - len1;
         assert((len1 == len2) || (len1 == (len2+1)));
         
         p = head;
         ListNode* prev = NULL;
         for (int i = 0; i < len1; i++) {
             prev = p;
             p = p->next;
         }
         prev->next = NULL; //break the list into 2

         // p is the head of the second list: now reverse it 
         prev = p;
         p = p->next;
         prev->next = NULL;
         ListNode* next = NULL;
         while (p) {
             next = p->next;
             p->next = prev;
             prev = p;
             p = next;
         }
         ListNode* head2 = prev;

         // Now merge the two lists to get results
         ListNode* p1 = head;
         ListNode* q1 = p1->next;
         ListNode* p2 = head2;
         ListNode* q2 = p2->next;
         while (p2) {
             //insert 'p2' between 'p1'/'q1'
             p1->next = p2;
             p2->next = q1;

             p1 = q1;
             if (p1) q1 = p1->next;
             p2 = q2;
             if (p2) q2 = p2->next;
         }

         return;
     }
};

int main()
{
    Solution s;
    ListNode n1(1);
    ListNode n2(3);
    ListNode n3(5);
    ListNode n4(6);
    ListNode n5(4);
    ListNode n6(2);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    s.reorderList(&n1);

    printList(&n1);
}

