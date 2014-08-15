/*
   Given a linked list and a value x, partition it such that all nodes less
   than x come before nodes greater than or equal to x.

   You should preserve the original relative order of the nodes in each of the
   two partitions.

   For example,
   Given 1->4->3->2->5->2 and x = 3,
   return 1->2->2->4->3->5.
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
     ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        
        ListNode *prev = NULL, *p = head;
        ListNode dummy(0); // head of all nodes >= x
        ListNode *dummyTail = &dummy;
        
        while (p) {
            if (p->val >= x) { // remove from head and append to dummy
                if (prev) prev->next = p->next;
                else head = p->next;
                dummyTail->next = p;
                dummyTail = p;
            }
            else {
                prev = p;
            }
            p = p->next;
        }
        dummyTail->next = NULL;
        if (prev) prev->next = dummy.next;
        return prev ? head : dummy.next;
     }
};

int main()
{
    Solution s;
    ListNode* ret;

    ListNode n1(1);
    ListNode n2(4);
    ListNode n3(3);
    ListNode n4(2);
    ListNode n5(5);
    ListNode n6(2);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ret = s.partition(&n1, 3);

    while (ret) {
        cout << ret->val << ",";
        ret = ret->next;
    }
    cout << endl;
}

