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
        TreeNode *prev = NULL;
        stack<TreeNode*> stk;
        if (!root) return ret;

        stk.push(root);
        while (!stk.empty()) {
            TreeNode *tp = stk.top();
            if (tp->left && (!prev || (prev != tp->left&&prev != tp->right))) {
                stk.push(tp->left);
                prev = tp;
                continue;
            }
            if (!prev || prev != tp->right) ret.push_back(tp->val);
            if (tp->right && prev != tp->right) {
                stk.push(tp->right);
                continue;
            }
            prev = tp;
            stk.pop();
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
