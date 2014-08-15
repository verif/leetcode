/*
   Given a binary tree, find its minimum depth.

   The minimum depth is the number of nodes along the shortest path from the
   root node down to the nearest leaf node.
*/

#include <iostream>
using namespace std;

/**
   * Definition for binary tree
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
*/

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     int minDepth(TreeNode *root) {
         if (!root) return 0;
         if (!root->left && !root->right) return 1;
         else if (!root->left) {
             return minDepth(root->right) + 1;
         } 
         else if (!root->right) {
             return minDepth(root->left) + 1;
         } 
         else {
             int minLeft = minDepth(root->left);
             int minRight = minDepth(root->right);
             if (minLeft < minRight) {
                 return minLeft + 1;
             }
             else {
                 return minRight + 1;
             }
         }
     }
};

int main()
{
    Solution s;
    int ret;

    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);

    n1.left = &n2;
    n2.left = &n3;
    n3.left = &n4;
    n6.left = &n5;
    n1.right = &n6;

    ret = s.minDepth(&n5);
    cout << ret << endl;
}
