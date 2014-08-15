/*
   Given an array of non-negative integers, you are initially positioned at the
   first index of the array.
   Each element in the array represents your maximum jump length at that
   position.
   Your goal is to reach the last index in the minimum number of jumps.

   For example:
   Given array A = [2,3,1,1,4]
   The minimum number of jumps to reach the last index is 2. (Jump 1 step from
   index 0 to 1, then 3 steps to the last index.)
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
     int jump(int A[], int n) {
        if (n < 2) return 0;
        int nextStart = 0, nextEnd = 0, steps = 0, max = 0;
        
        while (1) {
            for (int i = nextStart; i <= nextEnd; i++) {
                max = std::max(i+A[i], max);
            }
            steps++;
            if (max >= n-1) return steps;
            nextStart = nextEnd + 1;
            if (max == nextEnd) { // infinite loop - won't be able to reach the last index
                return INT_MAX;
            }
            nextEnd = max;
        }
        return steps;
     }
};

int main()
{
    Solution s;
    int ret;
    int A[] = {2,3,1,1,4};

    ret = s.jump(A, 5);
    cout << ret << endl;
}
