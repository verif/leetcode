/*
   Given a binary tree, find its maximum depth.

   The maximum depth is the number of nodes along the longest path from the
   root node down to the farthest leaf node.
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
#include <queue>
#include <iostream>
#include <assert.h>
using namespace std;

typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     int maxDepth(TreeNode *root) {
	 int ret = 0;
	 int lmax, rmax;
	 if (!root) return 0;
	 lmax = 1 + maxDepth(root->left);
	 rmax = 1 + maxDepth(root->right);
	 ret = lmax > rmax ? lmax : rmax;

	 return ret;
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
    TreeNode n7(7);

    n1.right = &n2;
    n2.right = &n3;
    n3.right = &n4;
    n4.right = &n5;
    n5.right = &n6;
    n6.right = &n7;

    ret = s.maxDepth(&n1);
    cout << ret << endl;

    return 0;
}
