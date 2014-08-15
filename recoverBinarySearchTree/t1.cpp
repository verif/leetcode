/*
   Two elements of a binary search tree (BST) are swapped by mistake.
   Recover the tree without changing its structure.

         5
        / \
       3   4
      / \   \
     2   6   7
    /
   1

   4 <=> 6
  
   original DFS sequence: 1, 2, 3, 4, 5, 6, 7
   wrong DFS sequence: 1, 2, 3, 6, 5, 4, 7
Note:
A solution using O(n) space is pretty straight forward. Could you devise a
constant space solution?
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

#include <vector>
#include <iostream>
using namespace std;

typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

// Real constant solution with constant space during tree traversal is
// complicated. Another way is to modify the left/right node along the way so
// that during the traversal, we keep track of the parents.
class Solution {
public:
     void MorriTraversal(TreeNode* root) {
         if (!root) return;
         TreeNode* p = root;
         while (p) {
             if (!p->left) {
                 cout << p->val << ",";
                 p = p->right;
                 continue;
             }
             TreeNode* prev = p->left;
             while (prev->right && prev->right != p) {
                 prev = prev->right;
             }
             if (!prev->right) {
                 prev->right = p;
                 p = p->left;
                 continue;
             }
             else {
                 cout << p->val << ",";
                 prev->right = NULL;
                 p = p->right;
             }
         }
     }
     void inorderTraverse(TreeNode *root, TreeNode* &first, TreeNode* &second,
                          TreeNode* &prev) {
         if (!root) return;
         inorderTraverse(root->left, first, second, prev);

         // visit root
         if (prev && prev->val > root->val) {
             if (!first) first = prev;
             second = root;
         }
         prev = root;
         inorderTraverse(root->right, first, second, prev);
     }
     void recoverTree(TreeNode *root) {
         if (!root) return;
         TreeNode *first = NULL;
         TreeNode *second = NULL;
         TreeNode *prev = NULL;

         inorderTraverse(root, first, second, prev);
         int tmp = first->val;
         first->val = second->val;
         second->val = tmp;

         return;
     }
};

int main()
{
    Solution s;
    TreeNode n1(5);
    TreeNode n2(3);
    TreeNode n3(4);
    TreeNode n4(2);
    TreeNode n5(6);
    TreeNode n6(7);
    TreeNode n7(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    n4.left = &n7;

    s.recoverTree(&n1);
    cout << endl;
    s.MorriTraversal(&n1);
    cout << endl;

    TreeNode n8(1);
    TreeNode n9(0);
    TreeNode n10(-1);

    n8.left = &n10;
    n8.right = &n9;
    s.recoverTree(&n8);
    cout << endl;
    s.MorriTraversal(&n8);
    cout << endl;

    TreeNode n11(3);
    TreeNode n12(1);
    TreeNode n13(2);
    n11.right = &n12;
    n12.left = &n13;
    s.recoverTree(&n11);
    cout << endl;
    s.MorriTraversal(&n11);
    cout << endl;

    TreeNode n14(0);
    TreeNode n15(1);
    n14.left = &n15;
    s.recoverTree(&n14);
    cout << endl;
    s.MorriTraversal(&n14);
    cout << endl;
}
