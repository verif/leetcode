/*
   Reverse a linked list. Do it in-place and in one-pass.
   For example:
   Given 1->2->3->4->5->NULL
   return 5->4->3->2->1

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
     ListNode *reverseLinkedList(ListNode *head) {
         if (!head) return NULL;

         ListNode* nhead = reverseLinkedList(head->next);
         if (!nhead) return head;
         head->next->next = head;
         head->next = NULL;

         return nhead;
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

    ret = s.reverseLinkedList(&n1);

    while (ret) {
        cout << ret->val << "->";
        ret = ret->next;
    }
    cout << endl;
}

