/*
   Given a binary tree and a sum, determine if the tree has a root-to-leaf path
   such that adding up all the values along the path equals the given sum.
   For example:
   Given the below binary tree and sum = 22,
                 5
                / \
               4   8
              /   / \
             11  13  4
            /  \    / \
           7    2  5   1

    return
    [
       [5,4,11,2],
       [5,8,4,5]
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
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
     vector<vector<int> > pathSum(TreeNode *root, int sum) {
         vector<vector<int>> ret;
         if (!root) return ret;

         if (!root->left && !root->right && root->val == sum) {
	     vector<int> v;
	     v.push_back(root->val);
             ret.push_back(v);
	     return ret;
	 }
         vector<vector<int>>::iterator it;
	 if (root->left) {
	     vector<vector<int>> lret = pathSum(root->left, sum - root->val);
	     vector<int> v;
             for (it = lret.begin(); it != lret.end(); it++) {
		 v = *it;
		 v.insert(v.begin(), root->val);
		 ret.push_back(v);
	     }
	 }
	 if (root->right) {
	     vector<int> v;
	     vector<vector<int>> rret = pathSum(root->right, sum - root->val);
             for (it = rret.begin(); it != rret.end(); it++) {
		 v = *it;
		 v.insert(v.begin(), root->val);
		 ret.push_back(v);
	     }
	 }
	
	 return ret;
     }
};

static void printPathSum(vector<vector<int>> &path)
{
    vector<vector<int>>::const_iterator it1;
    vector<int>::const_iterator it2;
    cout << "[" << endl;
    for (it1 = path.begin(); it1 != path.end(); it1++) {
	cout << "   [";
	vector<int> v = *it1;
	for (it2 = v.begin(); it2 != v.end(); it2++) {
	    cout << *it2 << ",";
	}
	cout << "]" << endl;;
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<vector<int>> ret;

    TreeNode n1(5);
    TreeNode n2(4);
    TreeNode n3(8);
    TreeNode n4(11);
    TreeNode n5(13);
    TreeNode n6(4);
    TreeNode n7(7);
    TreeNode n8(2);
    TreeNode n9(5);
    TreeNode n10(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.left = &n9;
    n6.right = &n10;

    ret = s.pathSum(&n1, 22);

    printPathSum(ret);
}
