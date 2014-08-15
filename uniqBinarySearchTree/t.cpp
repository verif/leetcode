/*
   Given n, generate all structurally unique BST's (binary search trees) that
   store values 1...n.
   For example,
   Given n = 3, your program should return all 5 unique BST's shown below.
      1         3     3      2      1
       \       /     /      / \      \
        3     2     1      1   3      2
       /     /       \                 \
      2     1         2                 3
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

// dynamic programming
class Solution {
public:
     void insertSubTreeAtRoot(vector<TreeNode*>& lv, vector<TreeNode*>& rv,
                              int rootVal, vector<TreeNode*>& res)
     {
         int i, j;
         for (i = 0; !lv.size() || i < lv.size(); i++) {
             for (j = 0; !rv.size() || j < rv.size(); j++) {
                 TreeNode* root = new TreeNode(rootVal);
                 root->left = lv.size() ? lv[i] : NULL;
                 root->right = rv.size() ? rv[j] : NULL;
                 res.push_back(root);
                 if (!rv.size()) break;
             }
             if (!lv.size()) break;
         }
     }

     vector<TreeNode *> generateTrees(int n) {
         // intermediate results for 'j'(2nd idx) numbers from 'i'(1st idx)
         vector<TreeNode *> p[n+2][n+2];
         int i;

         if (!n) {
             vector<TreeNode *> ret;
             ret.push_back(NULL);
             return ret;
         }

         // initial condition
         for (i = 1; i <= n; i++) {
             p[i][1].push_back(new TreeNode(i)); 
         }
         
         int j; // number of numbers
         for (j = 2; j <= n; j++) {
            for (i = 1; i <= n-j+1; i++) {
                for (int k = i; k < i+j; k++) { // 'k' as root
                    insertSubTreeAtRoot(p[i][k-i], p[k+1][i+j-k-1], k, p[i][j]);
                }
            }
         }

         return p[1][n];
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
    vector<TreeNode *> ret;
    int n = 5;
    int i;

    ret = s.generateTrees(n);
    cout << ret.size() << endl;
    /*
    for(i = 0; i < ret.size(); i++) {
        cout << "Print New Tree:" << endl;
        printTree(ret[i]);
    }
    */
}
