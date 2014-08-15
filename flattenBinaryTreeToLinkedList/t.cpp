/*
   Flatten Binary Tree to Linked List Total Accepted: 9687 Total Submissions:
   36292 My Submissions
   Given a binary tree, flatten it to a linked list in-place.
   For example,
   Given
            1
           / \
          2   5
         / \   \
        3   4   6
   The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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

#include <iostream>
#include <assert.h>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

// Solution: recursive code should be shortest 
class Solution {
public:
     TreeNode* flattenRecur(TreeNode *root) {
         if (!root) return NULL;
         TreeNode* lastLeft = flattenRecur(root->left);
         TreeNode* lastRight = flattenRecur(root->right);

         if (lastLeft) {
             lastLeft->right = root->right;
             root->right = root->left;
             root->left = NULL;
         }

         TreeNode* ret = lastRight ? lastRight : lastLeft ? lastLeft : root;
         return ret;
     }

     void flatten(TreeNode *root) {
         flattenRecur(root);
     }
};

static void printFlattenedTree(TreeNode* root)
{
    TreeNode* p = root;
    while (p) {
        cout << p->val << " ";
        assert(!p->left);
        p = p->right;
    }
    cout << endl;
}

int main()
{
    Solution s;
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);

    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;

    s.flatten(&n1);

    printFlattenedTree(&n1);
}
