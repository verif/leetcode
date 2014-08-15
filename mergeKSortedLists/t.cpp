/*
   Merge k sorted linked lists and return it as one sorted list. Analyze and
   describe its complexity.
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
#include <vector>

// Assuming there are n lists, each with k elements. The best algorithm will
// take nklog(k) time by: 
// 1. sorting the first element of each list (klogk)
// 2. Every time we insert an element to the final list, remove first element
// from (1). 
// 3. Insert the next element of the one removed in (2), and insert it to (1),
// which shall take log(n) time
// We need to insert n*k elements, each takes log(k), hence nklog(n)

// Finally, I am a lazy person and will not implement the above algorithm. I
// will just write a simpler version, which takes n*k*k time

#include <iostream>

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
     ListNode *merge2Lists(ListNode* h1, ListNode* h2) {
         if (!h1) return h2;
         if (!h2) return h1;

         ListNode *head = NULL;
         ListNode *p1 = NULL;
         ListNode *p2 = NULL;
         if (h1->val < h2->val) {
             head = p1 = h1;
             p2 = h2;
         }
         else {
             head = p1 = h2;
             p2 = h1;
         }

         // Merge p2 to p1
         ListNode *prev = NULL;
         while (p1 && p2) {
             while (p1 && p1->val <= p2->val) {
                 prev = p1;
                 p1 = p1->next;
             }
             prev->next = p2;
             if (!p1) break;
             while (p2 && p1->val >= p2->val) {
                 prev = p2;
                 p2 = p2->next;
             }
             prev->next = p1;
         }

         return head;
     }

     ListNode *mergeKLists(std::vector<ListNode *> &lists) {
         int num = lists.size();
         if (!num) return NULL;
         if (num == 1) return lists[0];
         ListNode *head = lists[0];
         for (int i = 0; i < num-1; i++) {
             head = merge2Lists(head, lists[i+1]);
         }
         return head;
     }
};

int main()
{
    Solution s;
    ListNode l11(1), l21(3), l31(5), l41(7), l51(9);
    ListNode l12(2), l22(4), l32(6), l42(8), l52(10);
    ListNode l13(11), l23(12), l33(13), l43(14), l53(15);
    ListNode l14(-5), l24(-4), l34(-3), l44(-2), l54(-1);
    ListNode l15(0), l25(7), l35(14), l45(21), l55(28);
    std::vector<ListNode *>  lists {&l11, &l12, &l13, &l14, &l15};
    ListNode *ret;

    l11.next = &l21; l21.next = &l31; l31.next = &l41; l41.next = &l51;
    l12.next = &l22; l22.next = &l32; l32.next = &l42; l42.next = &l52;
    l13.next = &l23; l23.next = &l33; l33.next = &l43; l43.next = &l53;
    l14.next = &l24; l24.next = &l34; l34.next = &l44; l44.next = &l54;
    l15.next = &l25; l25.next = &l35; l35.next = &l45; l45.next = &l55;

    ret = s.mergeKLists(lists);
    while (ret) {
        std::cout << ret->val << "," ;
        ret = ret->next;
    }
    std::cout << std::endl;
}

