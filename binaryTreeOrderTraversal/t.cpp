/*
   Given a binary tree, return the bottom-up level order traversal of its
   nodes' values. (ie, from left to right, level by level from leaf to root).

   For example:
   Given binary tree {3,9,20,#,#,15,7},
       3
      / \
     9  20
       /  \
      15   7

   return its bottom-up level order traversal as:
                   [
                    [15,7]
                    [9,20],
                    [3],
                   ]
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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     vector<vector<int> > levelOrderBottom(TreeNode *root) {
         vector<vector<int> > ret;
         if (!root) return ret;
         queue<TreeNode*> q;
         queue<TreeNode*> next;
         q.push(root);

         while (!q.empty()) {
             vector<int> v;
             while (!q.empty()) {
                 TreeNode* p = q.front();
                 q.pop();
                 v.push_back(p->val);
                 if (p->left) next.push(p->left);
                 if (p->right) next.push(p->right);
             }
             ret.insert(ret.begin(), v);
             q = next;
             while (!next.empty()) next.pop();
         }

         return ret;
     }
};

static void printOrder(vector<vector<int>>& vec)
{
    vector<vector<int>>::const_iterator it1;
    cout << "[" << endl;
    for (it1 = vec.begin(); it1 != vec.end(); it1++) {
        vector<int> v = *it1;
        vector<int>::const_iterator it2;
        cout << "   [";
        for (it2 = v.begin(); it2 != v.end(); it2++) {
            cout << *it2 << ",";
        }
        cout << "   ]" << endl;
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<vector<int>> ret;

    TreeNode n1(3);
    TreeNode n2(9);
    TreeNode n3(20);
    TreeNode n4(15);
    TreeNode n5(7);

    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;

    ret = s.levelOrderBottom(&n1);
    printOrder(ret);
}

