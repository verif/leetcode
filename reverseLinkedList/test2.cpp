/*
   Reverse a double linked list. Do it in-place and in one-pass.
   For example:
   Given 1->2->3->4->5->NULL
   return 5->4->3->2->1

*/

/**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *prev;
   *     ListNode *next;
   *     ListNode(int x) : val(x), prev(NULL), next(NULL) {}
   * };
*/

#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int x) : val(x), prev(NULL), next(NULL) {}
} ListNode;

class Solution {
public:
     ListNode *reverseLinkedList(ListNode *head) {
         if (!head) return NULL;
         if (!head->next) {
             head->prev = NULL;
             return head;
         }

         ListNode* nhead = reverseLinkedList(head->next);
         head->next->next = head;
         head->prev = head->next;
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
    n2.prev = &n1;
    n2.next = &n3;
    n3.prev = &n2;
    n3.next = &n4;
    n4.prev = &n3;
    n4.next = &n5;
    n5.prev = &n4;

    ret = s.reverseLinkedList(&n1);

    ListNode* tail = NULL;
    while (ret) {
        tail = ret;
        cout << ret->val << "->";
        ret = ret->next;
    }
    cout << endl;

    cout << "print from tail" << endl;
    while (tail) {
        cout << tail->val << "->";
        tail = tail->prev;
    }
    cout << endl;
}

