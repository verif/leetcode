/*
   Given two binary trees, write a function to check if they are equal or not.

   Two binary trees are considered equal if they are structurally identical and
   the nodes have the same value.
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
     bool isSameTree(TreeNode *p, TreeNode *q) {
	 if (p == q) return true;
	 if (p && !q) return false;
	 if (!p && q) return false;
	 if (p->val != q->val) return false;
	 return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
     }
};

int main()
{
     Solution s;
     bool ret;

     TreeNode n1(1);
     TreeNode n2(2);
     TreeNode n3(3);
     TreeNode n4(1);
     TreeNode n5(2);
     TreeNode n6(3);

    n1.left = &n2;
    n2.left = &n3;
    n4.left = &n5;
    n5.left = &n6;

    ret = s.isSameTree(&n1, NULL);
    cout << ret << endl;
}
