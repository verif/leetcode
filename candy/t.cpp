/*
   There are N children standing in a line. Each child is assigned a rating
   value.
   You are giving candies to these children subjected to the following

requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

do not assume that same ratings neighboring children should get the same
candies.
Consider this testcase: [1,2,2], the expected answer is 1+2+1=4.
*/

// Solution 1: brutal force. Each time, find the minimum rating from the
// remaining children, set their candies. Then, go to the next minimum. 
// This is O(n2) time and O(n) space

// Solution 2: scan from left to right, for sequences increase from left to
// right, assign index. Then, scan from right to left, assign index for
// sequences increasing from right to left. Use the larger number for each
// child during the two scan.
// This is O(n) time and O(n) space

// Solution 3: O(n) time and O(1) space: this is what I implement here

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int candy(vector<int> &ratings) {
         int n = ratings.size();
         int i, sum;

         if (!n) return 0;
         // initialize first child to 1
         sum = 1;
         int prev = 1;

         // start from 2nd child
         for (i = 1; i < n; i++) {
             int cur;
             if (ratings.at(i-1) < ratings.at(i)) {
                 cur = prev + 1; // (i)th child's candy is finalized here
                 prev = cur;
                 sum += cur;
             }
             else if (ratings.at(i-1) == ratings.at(i)) {
                 cur = 1;
                 prev = cur;
                 sum += cur;
             }
             else {
                 // This is the hard part, where we may change (i-1) child's
                 // candy number
                 int orig = prev;
                 int j;
                 prev = 1;
                 for (j = i-1; j < n-1; j++) {
                     if (ratings.at(j) > ratings.at(j+1)) {
                         sum+= prev;
                         prev++;
                     }
                     else {
                         break;
                     }
                 }
                 if (prev > orig) {
                     sum += (prev-orig);
                 }
                 prev = 1;;
                 i = j;
             }
         }

         return sum;
     }
};

int main()
{
    Solution s;
    vector<int> ratings = {1, 2, 3, 4, 3, 2, 1};
    int ret;

    ret = s.candy(ratings);
    cout << ret << endl;
}
