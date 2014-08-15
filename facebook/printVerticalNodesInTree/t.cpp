/*
   Print the sum of all the numbers at every vertical level in a binary tree

   For example:
   Given the below binary tree: 
                 5
                / \
               4   8
              /   / \
             11  13  4
            /  \      \
           7    2      1

    It should print:
	    7
	    11
	    6
	    18
	    8
	    4
	    1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    void getVerticalSumRecur(TreeNode *root, unordered_map<int, int>& vsum,
			     int cur, int &lmost) {
	if (!root) return;
	if (cur < lmost) lmost = cur;
	vsum[cur] += root->val;
	getVerticalSumRecur(root->left, vsum, cur-1, lmost);
	getVerticalSumRecur(root->right, vsum, cur+1, lmost);
    }

    vector<int> getVerticalSum(TreeNode *root) {
	unordered_map<int, int> vsum;
	int lmost;
	getVerticalSumRecur(root, vsum, 0, lmost);
		
	vector<int> res(vsum.size(), 0);
	for (int i = lmost; i < lmost+(int)vsum.size(); i++) {
	    res[i-lmost] = vsum[i];
	}

	return res;
    }
};

int main()
{
    Solution s;
    vector<int> ret;

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

    ret = s.getVerticalSum(&n1);
    for (int i = 0; i < ret.size(); i++) {
	std::cout << ret[i] << ",";
    }
    cout << endl << endl;
}
