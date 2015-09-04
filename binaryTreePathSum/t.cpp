/*
   You are given a binary tree in which each node contains a value. Design an
   algorithm to print all paths which sum up to that value. Note that it can be
   any path in the tree - it does not have to start at the root.

Note: a path in a tree cannot go beyond root, i.e., it has to be on either side
of the root, but not both.

   For example:
   Given the below binary tree and sum = 13,
                 5
                / \
               4   8
              /   / \
             11  13  4
            /  \      \
           7    2      1
   
    Print 3 paths: 5-8, 8-4-1, 11-2

    Give sum = 22:
    print: 4-5-8-4-1, 4-11-7, 5-4-11-2
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
    void getPathSumRecur(TreeNode *root, int sum, vector<int>& buffer, 
                         vector<vector<int>> &res) {
        if (!root) return;
        buffer.push_back(root->val);
        int tmp = 0;
        vector<int> vec;
        for (int i = buffer.size() - 1; i >= 0; i--) {
            tmp += buffer[i];
            vec.push_back(buffer[i]);
            if (tmp == sum) {
                res.push_back(vec);
            }
        }
        getPathSumRecur(root->left, sum, buffer, res);
        getPathSumRecur(root->right, sum, buffer, res);
        buffer.resize(buffer.size() - 1);
    }

    vector<vector<int>> getPathSum(TreeNode *root, int sum) {
        vector<int> buffer;
        vector<vector<int>> res;

        getPathSumRecur(root, sum, buffer, res);

        return res;
    }
};

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
    TreeNode n9(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.right = &n9;

    ret = s.getPathSum(&n1, 13);
    for (int i = 0; i < ret.size(); i++) {
	for (int j = 0; j < ret[i].size(); j++) {
	    std::cout << ret[i][j] << ",";
	}
	std::cout << std::endl;
    }

    cout << endl << endl;

    ret = s.getPathSum(&n1, 22);
    for (int i = 0; i < ret.size(); i++) {
	for (int j = 0; j < ret[i].size(); j++) {
	    std::cout << ret[i][j] << ",";
	}
	std::cout << std::endl;
    }
}
