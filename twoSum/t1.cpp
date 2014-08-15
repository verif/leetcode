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
        vector<int> res;
        if (numbers.size() < 2) return res;
        
        vector<int> sorted = numbers;
        std::sort(sorted.begin(), sorted.end());
        int idx1 = 0, idx2 = sorted.size()-1;
        
        while (idx1 < idx2) {
            int sum = sorted[idx1]+sorted[idx2];
            if (sum == target) break;
            else if (sum < target) idx1++;
            else idx2--;
        }
        
        int i1 = -1, i2 = -1;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == sorted[idx1] && i1 == -1) i1 = i+1;
            else if (numbers[i] == sorted[idx2] && i2 == -1) i2 = i+1;
        }
        
        res.push_back(std::min(i1, i2)); res.push_back(std::max(i1, i2));
        return res;
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
