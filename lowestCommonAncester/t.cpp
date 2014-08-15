/*
   given is a binary tree, write a function that returns Lowest Common Ancestor
   of two given nodes
*/

#include <iostream>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
} TreeNode;

class LCA {
public:
    TreeNode* findCommonAncester(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	if (!n1 || !n2 || !root) return NULL;	
	if (root == n1 || root == n2) return root;
	TreeNode *lret = findCommonAncester(root->left, n1, n2);
	TreeNode *rret = findCommonAncester(root->right, n1, n2);
	if (lret && rret) return root;
	return lret ? lret : rret;
    }
};

int main()
{
    LCA lca;
/*
            1
           / \
          2   5
         / \   \
        3   4   6
*/
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);

    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;

    TreeNode * ret = lca.findCommonAncester(&n1, &n3, &n4);
    cout << ret->val << endl;
    ret = lca.findCommonAncester(&n1, &n3, &n5);
    cout << ret->val << endl;
}
