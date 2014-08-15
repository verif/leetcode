/*
   Given a binary tree, determine if it is a valid binary search tree (BST).

   Assume a BST is defined as follows:
   The left subtree of a node contains only nodes with keys less than the
   node's key.
   The right subtree of a node contains only nodes with keys greater than the
   node's key.
   Both the left and right subtrees must also be binary search trees.
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
    bool isValidBSTRecur(TreeNode *root, int &min, int &max) {
	if (!root) return true;
	int lmin, lmax;
	int rmin, rmax;
        if (root->left) {
            lmin = lmax = root->val;
            if (!isValidBSTRecur(root->left, lmin, lmax)) return false;
            if (root->val <= lmax) return false;
            min = lmin;
        }
        else {
            min = root->val;
        }
        if (root->right) {
            rmin = rmax = root->val;
            if (!isValidBSTRecur(root->right, rmin, rmax)) return false;
            if (root->val >= rmin) return false;
            max = rmax;
        }
        else {
            max = root->val;
        }
	return true;
    }
    bool isValidBST(TreeNode *root) {
	int min;
        int max;
	return isValidBSTRecur(root, min, max);
    }
};

int main()
{
    Solution s;
    bool ret;
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

    ret = s.isValidBST(&n1);
    cout << ret << endl;

    TreeNode n8(1);
    TreeNode n9(1);
    n8.left = &n9;
    ret = s.isValidBST(&n8);
    cout << ret << endl;
}
