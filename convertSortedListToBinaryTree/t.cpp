/*
Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.
*/

#include <iostream>
#include <queue>
using namespace std;

/**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode(int x) : val(x), next(NULL) {}
   * };
*/
/**
  * Definition for binary tree
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
*/

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     TreeNode *sortedListToBSTRecur(ListNode* &head, int len) {
         if (!head || !len) return NULL;
         if (len == 1) {
             TreeNode* tn = new TreeNode(head->val);
             head = head->next;
             return tn;
         }

         int llen = len/2;
         int rlen = len - 1 - llen;
         TreeNode* left = sortedListToBSTRecur(head, llen);
         TreeNode* root = new TreeNode(head->val);
         head = head->next;
         TreeNode* right = sortedListToBSTRecur(head, rlen);
         root->left = left;
         root->right = right;

         return root;
     }
     TreeNode *sortedListToBST(ListNode *head) {
         int len = 0;
         ListNode* p = head;
         while (p) {
             len++;
             p = p->next;
         }
         return sortedListToBSTRecur(head, len);
     }
};

static void printTree(TreeNode* root)
{
    if (!root) return;
    queue<TreeNode*> q;
    queue<TreeNode*> next;
    q.push(root);
    TreeNode* p;
    while (!q.empty()) {
        while (!q.empty()) {
            p = q.front();
            q.pop();
            cout << p->val << " ";
            if (p->left) next.push(p->left);
            else cout << " empty left";
            if (p->right) next.push(p->right);
            else cout << " empty right";
        }
        q = next;
        while (!next.empty()) next.pop();
        cout << endl;
    }
    cout << endl;

}

int main()
{
    Solution s;
    TreeNode* ret;

    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    ListNode l7(7);
    ListNode l8(8);
    ListNode l9(9);
    ListNode l10(10);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    l8.next = &l9;
    l9.next = &l10;

    ret = s.sortedListToBST(&l1);
    printTree(ret);
}
