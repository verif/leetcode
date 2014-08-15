/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path
could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3
         The root-to-leaf path 1->2 represents the number 12.
         The root-to-leaf path 1->3 represents the number 13.
         Return the sum = 12 + 13 = 25.
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

class Solution {
public:
     void traverseTree(TreeNode* root, int &sum, int cur)
     {
         cur = 10 * cur + root->val;
         if (root->left) {
             traverseTree(root->left, sum, cur);
         }
         if (root->right) {
             traverseTree(root->right, sum, cur);
         }
         if (!root->left && !root->right) { // leaf node
             sum += cur;
         }
     }
     int sumNumbers(TreeNode *root) {
         if (!root) return 0;
         int sum = 0;
         int cur = 0;

         traverseTree(root, sum, cur);

         return sum;
     }
};

int main()
{
    Solution s;
    int ret;
    TreeNode tn1(1);
    TreeNode tn2(2);
    TreeNode tn3(3);
    TreeNode tn4(4);
    TreeNode tn5(5);

    tn1.left = &tn2;
    tn1.right = &tn3;
    tn2.left = &tn4;
    tn3.right = &tn5;

    ret = s.sumNumbers(&tn2);
    cout << ret << endl;
}

