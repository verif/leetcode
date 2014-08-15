/*
   Given an array of integers, find two numbers such that they add up to a
   specific target number.

   The function twoSum should return indices of the two numbers such that they
   add up to the target, where index1 must be less than index2. Please note
   that your returned answers (both index1 and index2) are not zero-based.
   You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <vector>
#include <algorithm> // for 'sort'
#include <iostream>
using namespace std;

class Solution {
public:
     vector<int> twoSum(vector<int> &numbers, int target) {
         vector<int> ret;
         vector<int> sorted = numbers;

         int v1, v2;
         sort(sorted.begin(), sorted.end());
         unsigned int i = 0;
         unsigned int j = sorted.size()-1;

         while (j > i) {
             int sum = sorted[i]+sorted[j];
             if (sum == target) {
                 v1 = sorted[i];
                 v2 = sorted[j];
                 break;
             }
             else if (sum > target) {
                 j--;
             }
             else {
                 i++;
             }
         }

         for (unsigned int i = 0; i < numbers.size(); i++) {
             if (numbers[i] == v1 || numbers[i] == v2) {
                 if (ret.empty()) ret.push_back(i+1);
                 else if (numbers[ret[0]-1] + numbers[i] == target) ret.push_back(i+1);
             }
         }

         return ret;
     }
};

int main()
{
    Solution s;
    vector<int> ret;
    vector<int> numbers;

    numbers = {150,24,79,50,88,345,3};
    ret = s.twoSum(numbers, 200);
    cout << ret[0] << "," << ret[1] << endl;

    numbers = {2,7,11,15};
    ret = s.twoSum(numbers, 9);
    cout << ret[0] << "," << ret[1] << endl;


    numbers = {3,2,4};
    ret = s.twoSum(numbers, 6);
    cout << ret[0] << "," << ret[1] << endl;

    numbers = {0,4,3,0};
    ret = s.twoSum(numbers, 0);
    cout << ret[0] << "," << ret[1] << endl;
}
