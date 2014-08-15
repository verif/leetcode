/*
   Given a binary tree and a sum, determine if the tree has a root-to-leaf path
   such that adding up all the values along the path equals the given sum.
   For example:
   Given the below binary tree and sum = 22,
                 5
                / \
               4   8
              /   / \
             11  13  4
            /  \      \
           7    2      1
                                                                                return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     bool hasPathSum(TreeNode *root, int sum) {
         if (!root) return false;
         if (!root->left && !root->right && root->val == sum) return true;

         bool ret;
         if (root->left) {
             ret = hasPathSum(root->left, sum - root->val);
             if (ret) return true;
         }
         if (root->right) {
             ret = hasPathSum(root->right, sum - root->val);
             if (ret) return true;
         }

         return false;
     }
};

int main()
{
    Solution s;
    bool ret;

    TreeNode n1(5);
    TreeNode n2(4);
    TreeNode n3(8);
    TreeNode n4(11);
    TreeNode n5(13);
    TreeNode n6(4);
    TreeNode n7(7);
    TreeNode n8(2);
    TreeNode n9(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.right = &n9;

    ret = s.hasPathSum(NULL, 13);
    cout << ret << endl;
}
