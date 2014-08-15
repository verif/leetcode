/*
   Given a binary tree, return the preorder traversal of its nodes' values.
   For example:
   Given binary tree {1,#,2,3},
        1
         \
          2
         /
        3
                      return [3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
   /**
    * Definition for binary tree
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     vector<int> preorderTraversal(TreeNode *root) {
         stack<TreeNode*> nodeStack;
         vector<int> ret;

         if (!root) return ret;

         nodeStack.push(root);

         ret.push_back(root->val);

         TreeNode* prev = NULL;
         while (!nodeStack.empty()) {
             TreeNode* tn = nodeStack.top();
             if (tn->left &&(!prev||(prev != tn->left && prev != tn->right))) {
                 nodeStack.push(tn->left);
                 ret.push_back(tn->left->val);
                 prev = tn;
                 continue;
             }
             if (tn->right && (prev != tn->right)) {
                 nodeStack.push(tn->right);
                 ret.push_back(tn->right->val);
                 prev = tn;
                 continue;
             }
             prev = tn;
             nodeStack.pop();
         }
         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> v;

    TreeNode n1(1);
    TreeNode n11(11);
    TreeNode n2(2);
    TreeNode n22(22);
    TreeNode n3(3);
    TreeNode n33(33);

    n1.left = &n11;
    n1.right = &n2;
    n2.left = &n3;
    n2.right = &n22;
    n3.left = &n33;

    v = s.preorderTraversal(&n1);

    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}
