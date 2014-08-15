/*
   Given n, how many structurally unique BST's (binary search trees) that store
   values 1...n?

   For example,
   Given n = 3, there are a total of 5 unique BST's.

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
     int numTrees(int n) {
         // intermediate results for 'j'(2nd idx) numbers from 'i'(1st idx)
         int p[n+2][n+2];
         int i,j;

         if (n < 2) return 1;

         for (i = 0; i < n+2; i++) {
             for (j = 0; j < n+2; j++) {
                 p[i][j] = 0;
             }
         }
         // initial condition
         for (i = 1; i <= n+1; i++) {
             p[i][1] = 1;
             p[i][0] = 1;
             p[n][i] = 1;
             p[n+1][i] = 1;
         }
         
         for (j = 2; j <= n; j++) {
            for (i = 1; i <= n-j+1; i++) {
                for (int k = i; k < i+j; k++) { // 'k' as root
                    p[i][j] += (p[i][k-i]*p[k+1][i+j-k-1]);
                }
            }
         }

         return p[1][n];
     }
};

int main()
{
    Solution s;
    int ret;
    int n = 5;
    int i;

    ret = s.numTrees(n);
    cout << ret << endl;
}
