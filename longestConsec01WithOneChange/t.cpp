/*
   Give an input array of value 0 or 1, change one of the array entry so that 
   we have longest consecutive 0 or 1.

   For example:
   [1 0 1] => change 0 to 1, the output is 3 (longest length)
   [1 1 0 1 0 0] => change 4th element from 1 to 0 and output is 4
*/

#include <iostream>

class Solution {
public:
    int longestConsecSeqWithChange(int A[], int n) {
        if (n < 2) return n;
        int max = 0;
        int cur = 0;
        int i = 0;

        while (i < n) {
            cur = 1;
            while (i < n-1 && A[i] == A[i+1]) {
                i++;
                cur++;
            }
            // check if next different value is a single sequence
            if (i >= n-2 || A[i+1] == A[i+2]) {
                i++;
                if (i != n) cur++;
                max = max < cur ? cur : max;
            }
            // flip the next value
            else { 
                i += 2;
                int j = i;
                cur += 2;
                while (j < n-1 && A[j] == A[j+1]) {
                    j++;
                    cur++;
                }
                max = max < cur ? cur : max;
            }
        }

        return max;
    }
};

int main() {
    Solution s;
    int ret;

    int A0[] = {1};
    ret = s.longestConsecSeqWithChange(A0, 1);
    std::cout << ret << std::endl;

    int A[] = {1,0,1};
    ret = s.longestConsecSeqWithChange(A, 3);
    std::cout << ret << std::endl;

    int A1[] = {1, 1, 0, 1, 0, 0};
    ret = s.longestConsecSeqWithChange(A1, 6);
    std::cout << ret << std::endl;

    int A2[] = {1, 1, 1, 1, 1, 1};
    ret = s.longestConsecSeqWithChange(A2, 6);
    std::cout << ret << std::endl;

    int A3[] = {1, 0, 0, 1, 0, 0, 1, 0, 0, 0};
    ret = s.longestConsecSeqWithChange(A3, 10);
    std::cout << ret << std::endl;

}
