/*
   Given an array where elements are sorted in ascending order, convert it to a
   height balanced BST.
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
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     TreeNode *sortedArrayToBSTRecur(vector<int> &num, int start, int len) {
         if (!len) return NULL;
         TreeNode* root = NULL;
         if (len == 1) {
             root = new TreeNode(num[start]);
             return root;
         }
         int llen = len/2;
         int rlen = len - llen - 1;
         int rstart = start + llen + 1;
         TreeNode* left = sortedArrayToBSTRecur(num, start, llen);
         root = new TreeNode(num[start+llen]);
         TreeNode* right = sortedArrayToBSTRecur(num, rstart, rlen);
         root->left = left;
         root->right = right;
         return root;
     }
     TreeNode *sortedArrayToBST(vector<int> &num) {
         int len = num.size();
         return sortedArrayToBSTRecur(num, 0, len);
     }
};

static void printTree(TreeNode* root)
{
    if (!root) return;
    queue<TreeNode*> q;
    queue<TreeNode*> next;
    q.push(root);
    TreeNode* p;
    while (!q.empty()) {
        while (!q.empty()) {
            p = q.front();
            q.pop();
            cout << p->val << " ";
            if (p->left) next.push(p->left);
            else cout << " el ";
            if (p->right) next.push(p->right);
            else cout << " er ";
        }
        q = next;
        while (!next.empty()) next.pop();
        cout << endl;
    }
    cout << endl;

}

int main()
{
    Solution s;
    TreeNode* ret;
    vector<int> num = {1,2,3,4,5,6,7,8,9,10};

    ret = s.sortedArrayToBST(num);
    printTree(ret);
}
