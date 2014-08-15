/*
   Given a binary tree, check whether it is a mirror of itself (ie, symmetric
   around its center).
   For example, this binary tree is symmetric:
       1
      / \
     2   2
    / \ / \
   3  4 4  3
   But the following is not:
       1
      / \
     2   2
      \   \
       3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
     bool isSymmetricRecur(TreeNode* left, TreeNode* right) {
	 if (!left) return !right;
	 if (!right) return !left;
         if (left->val != right->val) return false;
	 return (isSymmetricRecur(left->left, right->right) &&
		 isSymmetricRecur(left->right, right->left));
     }

     bool isSymmetric(TreeNode *root) {
	 if (!root) return true;
	 return isSymmetricRecur(root->left, root->right);
     }
};

int main()
{
    Solution s;
    bool ret;

    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    TreeNode n4(3);
    TreeNode n5(4);
    TreeNode n6(4);
    TreeNode n7(3);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    ret = s.isSymmetric(&n1);
    cout << ret << endl;
}
