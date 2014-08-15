/*
   Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree
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

// Recursive functions are best for tree related problems: same here
class Solution {
public:
     TreeNode *buildTreeRecur(vector<int> &preorder, vector<int> &inorder, int
                              preBegin, int preEnd, int inBegin, int inEnd)
     {
         int mid;
         TreeNode* root = new TreeNode(preorder[preBegin]);
         if(preBegin > preEnd-1) {
             assert(inBegin > inEnd - 1);
             return NULL;
         }
         else if (preBegin == preEnd-1) {
             assert(inBegin == inEnd-1);
             return root;
         }
         for (int i = inBegin; i < inEnd; i++) {
             if (inorder[i] == preorder[preBegin]) {
                 mid = i;
                 break;
             }
         }
         TreeNode* left = buildTreeRecur(preorder, inorder, preBegin+1,
                                         preBegin+(mid-inBegin)+1, inBegin,
                                         mid);
         TreeNode* right = buildTreeRecur(preorder, inorder,
                                          preBegin+(mid-inBegin)+1, preEnd,
                                          mid+1, inEnd);
         root->left = left;
         root->right = right;
         return root;
     }
     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
         int len = preorder.size();
         assert(len == inorder.size());
         if (!len) return NULL;
         return buildTreeRecur(preorder, inorder, 0, len, 0, len);
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
            else cout << "el";
            if (p->right) next.push(p->right);
            else cout << "er";
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
    vector<int> preorder = {1,2,4,5,3,6,7,8};
    vector<int> inorder = {4,2,5,1,6,3,7,8};

    ret = s.buildTree(preorder, inorder);

    printTree(ret);
    return 0;
}
