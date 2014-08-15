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
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     int maxPathSumRecur(TreeNode *root, int &maxLeft, int &maxRight)
     {
         if (!root) {
             maxLeft = 0;
             maxRight = 0;
             return 0;
         }
         int mleft, mright;
         int ret, retl, retr;
         retl = maxPathSumRecur(root->left, mleft, mright);

         maxLeft = mleft > mright ? mleft : mright;
         maxLeft += root->val;
         maxLeft = maxLeft > root->val ? maxLeft : root->val;

         retr = maxPathSumRecur(root->right, mleft, mright);
         maxRight = mleft > mright ? mleft : mright;
         maxRight += root->val;
         maxRight = maxRight > root->val ? maxRight : root->val;

         ret = root->val;
         if (maxLeft > root->val) {
             ret += (maxLeft-root->val);
         }
         if (maxRight > root->val) {
             ret += (maxRight-root->val);
         }
         ret = root->left && ret < retl ? retl : ret;
         ret = root->right && ret < retr ? retr : ret;

         return ret;
     }

     int maxPathSum(TreeNode *root) {
         if (!root) return 0;
         int maxLeft, maxRight;
         int ret = maxPathSumRecur(root, maxLeft, maxRight);
         return ret;
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
