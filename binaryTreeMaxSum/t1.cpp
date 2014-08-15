/*
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
For example:
Given the below binary tree,
           1
          / \
         2   3
Return 6.
*/

/*
   * Definition for binary tree
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
*/

// Solutoin: DFS traversal. Get max(left tree)/max(right tree)
#include <iostream>
#include <climits>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     int maxPathSumRecur(TreeNode *root, int &max) {
         if (!root) return 0;
         int lv = maxPathSumRecur(root->left, max);
         int rv = maxPathSumRecur(root->right, max);
         int m = root->val;
         if (lv > 0) m += lv;
         if (rv > 0) m += rv;
         max = std::max(max, m);

         return std::max(lv, rv) > 0 ? root->val + std::max(lv, rv) : root->val;
     }
     int maxPathSum(TreeNode *root) {
         if (!root) return 0;
         int max = INT_MIN;
         (void)maxPathSumRecur(root, max);
         return max;
     }
};

int main()
{
    Solution s;
    TreeNode n1(9);
    TreeNode n2(6);
    TreeNode n3(-3);
    TreeNode n4(-6);
    TreeNode n5(2);
    TreeNode n6(2);
    TreeNode n7(-6);
    TreeNode n8(-6);
    TreeNode n9(-6);
    int ret;

    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    n5.left = &n6;
    n6.left = &n7;
    n6.right = &n8;
    n7.left = &n9;

    ret = s.maxPathSum(&n1);

    cout << ret << endl;
}
