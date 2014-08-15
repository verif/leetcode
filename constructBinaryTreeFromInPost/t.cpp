/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
     TreeNode *buildTreeRecur(vector<int> &postorder, vector<int> &inorder, int
                              postBegin, int postEnd, int inBegin, int inEnd)
     {
         int mid;
         TreeNode* root = new TreeNode(postorder[postEnd-1]);
         if(postBegin > postEnd-1) {
             assert(inBegin > inEnd - 1);
             return NULL;
         }
         else if (postBegin == postEnd-1) {
             assert(inBegin == inEnd-1);
             return root;
         }
         for (int i = inBegin; i < inEnd; i++) {
             if (inorder[i] == postorder[postEnd-1]) {
                 mid = i;
                 break;
             }
         }
         TreeNode* left = buildTreeRecur(postorder, inorder, postBegin,
                                         postBegin+(mid-inBegin), inBegin,
                                         mid);
         TreeNode* right = buildTreeRecur(postorder, inorder,
                                          postBegin+(mid-inBegin), postEnd-1,
                                          mid+1, inEnd);
         root->left = left;
         root->right = right;
         return root;
     }
     TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
         int len = postorder.size();
         assert(len == inorder.size());
         if (!len) return NULL;
         return buildTreeRecur(postorder, inorder, 0, len, 0, len);
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
    vector<int> inorder = {1,2,3,4}; // {4,5,2,6,8,7,3,1};
    vector<int> postorder = {3,4,2,1}; // {4,2,5,1,6,3,8,7};

    ret = s.buildTree(inorder, postorder);

    printTree(ret);
    return 0;
}
