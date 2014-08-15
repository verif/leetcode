/*
   Given a binary tree, determine if it is height-balanced.

   For this problem, a height-balanced binary tree is defined as a binary tree
   in which the depth of the two subtrees of every node never differ by more
   than 1.
*/

#include <iostream>
#include <queue>
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

// BFS should be the easiest solution
class Solution {
public:
     bool isBalanced(TreeNode *root) {
	 if (!root) return true;
	 queue<TreeNode*> q;
	 queue<TreeNode*> next;
	 q.push(root);
	 TreeNode* p;
	 bool noLeftOrRight = false;
	 while (!q.empty() && !noLeftOrRight) {
	     while (!q.empty()) {
                 p = q.front();
		 q.pop();
		 if (p->left && p->right) {
		     next.push(p->left);
		     next.push(p->right);
		 }
		 else {
		     noLeftOrRight = true;
		     if (p->left) next.push(p->left);
		     if (p->right) next.push(p->right);
		 }
	     }
	     q = next;
	     while (!next.empty()) next.pop();
	 }

	 if (noLeftOrRight) {
            while (!q.empty()) {
                 p = q.front();
                 q.pop();
		 if (p->left || p->right) return false;
	     }
	 }

	 return true;
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
    TreeNode n5(3);
    TreeNode n6(3);
    TreeNode n7(3);
    TreeNode n8(4);
    TreeNode n9(4);
    TreeNode n10(4);
    TreeNode n11(4);
    TreeNode n12(4);
    TreeNode n13(4);
    TreeNode n14(5);
    TreeNode n15(5);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = &n8;
    n4.right = &n9;
    n5.left = &n10;
    n5.right = &n11;
    n6.left = &n12;
    n6.right = &n13;
    n8.left = &n14;
    n8.right = &n15;
 //   n6.left = &n7;

    ret = s.isBalanced(&n1);
    cout << ret << endl;
}
