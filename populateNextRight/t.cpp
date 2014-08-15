/*
Given a binary tree
    struct TreeLinkNode {
              TreeLinkNode *left;
              TreeLinkNode *right;
              TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next
right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same
                                                 level, and every parent has
                                                 two children).
For example,
    Given the following perfect binary tree,
             1
            /  \
           2    3
          / \  / \
         4  5  6  7
    After calling your function, the tree should look like:
          1 -> NULL
         /  \
        2 -> 3 -> NULL
       / \  / \
      4->5->6->7->NULL
*/

/**
   * Definition for binary tree with next pointer.
   * struct TreeLinkNode {
   *  int val;
   *  TreeLinkNode *left, *right, *next;
   *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
   * };
*/

#include <iostream>
using namespace std;

typedef struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
} TreeLinkNode;

// BFS should solve the problem
class Solution {
public:
     void connect(TreeLinkNode *root) {
         if (!root) return;
         root->next = NULL;
         TreeLinkNode* head = root;

         while (head) {
             TreeLinkNode* first = NULL;
             TreeLinkNode* p = head;
             TreeLinkNode* prev = NULL;
             while (p) {
                 // Find the next pointer
                 if (p->left) {
                     if (!prev) {
                         prev = p->left;
                     }
                     else {
                         prev->next = p->left;
                         prev = p->left;
                     }
                     if (!first) first = p->left;
                 }
                 if (p->right) {
                     if (!prev) {
                         prev = p->right;
                     }
                     else {
                         prev->next = p->right;
                         prev = p->right;
                     }
                     if (!first) first = p->right;
                 }
                 p = p->next;
             }
             if (prev) prev->next = NULL;
             head = first;
         }
     }
};

static void printTree(TreeLinkNode* root)
{
    TreeLinkNode* p = root;
    TreeLinkNode* head = root;

    while (head) {
        p = head;
        head = NULL;
        while (p) {
            cout << p->val;
            if (p->left) {
                cout << " (left: " << p->left->val << ") "; 
                if (!head) head = p->left;
            }
            if (p->right) {
                cout << " (right: " << p->right->val << ") "; 
                if (!head) head = p->right;
            }
            if (p->next) {
                cout << " (Next: " << p->next->val << ") ";
            }
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    Solution s;
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    TreeLinkNode n6(6);
    TreeLinkNode n7(7);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    s.connect(&n1);
    printTree(&n1);
}
