#include <iostream>

/*
   You are given two linked lists representing two non-negative numbers. The
   digits are stored in reverse order and each of their nodes contain a single
   digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p, *last;
        
        bool carry = false;
        int v;
        while (p1 && p2) {
            v = p1->val + p2->val;
            if (carry) v++;
            if (v >= 10) {
                carry = true;
                v -= 10;
            }
            else {
                carry = false;
            }
            p = new ListNode(v);
            if (!ret) {
                ret = p;
            }
            else {
                last->next = p;
            }
            last = p;
            p1 = p1->next;
            p2 = p2->next;
        }
                p = p1 ? p1 : p2;
        while (p) {
            int v = p->val;
            if (carry) v++;
            if (v >= 10) {
                carry = true;
                v -= 10;
            }
            else {
                carry = false;
            }
            ListNode *p3 = new ListNode(v);
            last->next = p3;
            last = p3;
            p = p->next;
        }
        if(carry) {
            p = new ListNode(1);
            last->next = p;
        }
        return ret;
    }
};

int main() 
{
    // Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    // Output: 7 -> 0 -> 8
    Solution s;
    ListNode * n1;
    ListNode * n2;
    ListNode * p;
    int a1[] = {2, 4, 3};
    int a2[] = {5, 6, 4};

    for (int i = 0; i < sizeof(a1)/sizeof(int); i++) {
        if (i == 0) {
            n1 = new ListNode(a1[i]);
            p = n1;
        }
        else {
            p->next = new ListNode(a1[i]);
            p = p->next;
        }
    }

    for (int i = 0; i < sizeof(a2)/sizeof(int); i++) {
        if (i == 0) {
            n2 = new ListNode(a2[i]);
            p = n2;
        } 
        else {
            p->next = new ListNode(a2[i]);
            p = p->next;
        }   
    }       
    p = s.addTwoNumbers(n1, n2);
    while (p) {
        printf("%d", p->val);
        p = p->next;
    }
    printf("\n");
}
