/*
   Given a binary tree, return the inorder traversal of its nodes' values.
   For example:
   Given binary tree {1,#,2,3},
      1
       \
        2
       /
      3
    return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
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
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
	 vector<int> ret;
	 if (!root) return ret;
	 stack<TreeNode*> q;
	 TreeNode *p, *prev;
	 q.push(root);
 
	 prev = root;
	 while (!q.empty()) {
	     p = q.top();
	     if (p->left && prev != p->left && prev != p->right) {
		 q.push(p->left);
		 continue;
	     }
	     else if (p->right && prev != p->right) {
		 ret.push_back(p->val);
		 q.push(p->right);
		 continue;
	     }
	     if (prev != p->right) ret.push_back(p->val);
	     prev = p;
	     q.pop();
	 }
         return ret;
    }
};

int main()
{
    Solution s;
    vector<int> ret;
    
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);

    n1.right = &n2;
    n2.left = &n3;
    ret = s.inorderTraversal(&n1);

    for (int i = 0; i < ret.size(); i++) {
	cout << ret[i] << ",";
    }
    cout << endl;
}
