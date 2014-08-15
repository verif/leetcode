/*
   Implement next permutation, which rearranges numbers into the
   lexicographically next greater permutation of numbers.
   If such arrangement is not possible, it must rearrange it as the lowest
   possible order (ie, sorted in ascending order).
   The replacement must be in-place, do not allocate extra memory.

   Here are some examples. Inputs are in the left-hand column and its
   corresponding outputs are in the right-hand column.
   1,2,3 -> 1,3,2
   3,2,1 -> 1,2,3
   1,1,5 -> 1,5,1
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     void nextPermutation(vector<int> &num) {
         if (!num.size()) return;

         for (int i = num.size()-2; i >= 0; i--) {
             if (num[i] < num[num.size()-1]) {
                 for (int j = i+1; j < num.size(); j++) {
                     if (num[j] > num[i]) {
                         int tmp = num[i];
                         num[i] = num[j];
                         num[j] = tmp;
                         return;
                     }
                 }
             }
             else {
                 int tmp = num[i];
                 for (int j = i; j < num.size()-1; j++) {
                     num[j] = num[j+1];
                 }
                 num[num.size()-1] = tmp;
             }
         }
     }
};

int main()
{
    Solution s;

    vector<int> num = {1,2,3};

    s.nextPermutation(num);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << ",";
    }
    cout << endl;

    num = {3,2,1};
    s.nextPermutation(num);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << ",";
    }
    cout << endl;

    num = {1,1,5};
    s.nextPermutation(num);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << ",";
    }
    cout << endl;

    num = {4,2,3,1};
    s.nextPermutation(num);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << ",";
    }
    cout << endl;
}
