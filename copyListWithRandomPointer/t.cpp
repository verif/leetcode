/*
   A linked list is given such that each node contains an additional random
   pointer which could point to any node in the list or null.

   Return a deep copy of the list.
*/

/**
  * Definition for singly-linked list with a random pointer.
  * struct RandomListNode {
  *     int label;
  *     RandomListNode *next, *random;
  *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  * };
  */

#include <iostream>

using namespace std;

typedef struct RandomListNode {
    int label;
    RandomListNode* next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
} RandomListNode;

// A simple solution would be to create a map between cloned node and original
// node, and hence set the random pointers. But it takes O(n) space

// Another solution, which takes constant space, puts cloned node next to the
// original node during copy. However, this requires change to the original
// list, which cannot be read only.

class Solution {
public:
     RandomListNode *copyRandomList(RandomListNode *head) {
         if (!head) return NULL;

         // first clone the list without setting the random pointer
         RandomListNode* cloneHead = NULL;
         RandomListNode* p = head;
         RandomListNode* q = NULL;
         RandomListNode* prev = cloneHead;
         while (p) {
             q = new RandomListNode(p->label);
             if (!prev) {
                 cloneHead = q;
             }
             else {
                 prev->next = q;
             }
             prev = q;
             p = p->next;
         }

         // next merge two lists so that 'next' of the original node is the
         // cloned node
         prev = head;
         p = prev->next;
         q = cloneHead;
         RandomListNode* next = q->next;
         while (q) {
             next = q->next;
             prev->next = q;
             q->next = p;
             prev = p;
             if (!p) break;
             p = p->next;
             q = next;
         }

         // set the random pointer
         p = head;
         while (p) {
             p->next->random = p->random ? p->random->next : NULL;
             p = p->next->next;
         }

         // finally break the list
         p = head;
         while (p) {
             next = p->next;
             if (!next) break;
             p->next = p->next->next;
             p = next;
         }

         return cloneHead;
     }
};

static void printList(RandomListNode* head) {
    cout << "Print list: " << endl;
    while (head) {
        cout << head->label << endl;
        if (head->random) {
            cout << "random: " << head->random->label << endl;
        }
        head = head->next;
    }
}

int main()
{
    Solution s;
    RandomListNode* ret;

    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);
    RandomListNode n4(4);
    RandomListNode n5(5);
    RandomListNode n6(6);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    n1.random = &n3;
    n2.random = &n5;
    n3.random = &n6;
    // n4.random = &n4;
    n5.random = &n6;
    n6.random = &n6;

    printList(&n1);
    ret = s.copyRandomList(&n1);
    printList(ret);

    RandomListNode* p = &n1;
    while (p) {
        p->label = 0;
        p = p->next;
    }

    printList(&n1);

    printList(ret);
}

