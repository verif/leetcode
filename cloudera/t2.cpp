/*
   A file contains a billion integers, try to find any one integer that is not
   in the file.
*/

// Solution is: assuming integer of 32 bits:
// 1. Scan all the integers in the file. Have an array of size 1 << 16. 
//    for each integer, use first 16 bits as index to add one the array entry.
// 2. Now at least one of the entry is < (1 << 16). Pick that entry.
// 3. Scan the file again, only look at the last 16 bits that have the first 
//    16 bits in the array entry in (2). Use last 16 bits as index to set 1 
//    for another array entry. 
// 4. At the end, one of the array entry in (3) has to be 0. That index will be 
//    the last 16 bits of the missing integer, and index in (2) will be the
//    first 16 bits.

#include <iostream>
using namespace std;

class Solution {
public:
    int findMissingInteger(int A[], int len) {
        int low16[1 << 16] = {0};
        int hi16[1 << 16] = {0};
        int low = -1, hi = -1;

        for (int i = 0; i < len; i++) {
            hi16[A[i] >> 16]++;
        }

        for (int i = 0; i < (1 << 16); i++) {
            if (hi16[i] != (1 << 16)) {
                hi = i;
                break;
            }
        }

        for (int i = 0; i < len; i++) {
            if ((A[i] >> 16) != hi) continue;
            low16[A[i] & 0xffff] = 1;
        }

        for (int i = 0; i < (1 << 16); i++) {
            if (!low16[i]) {
                low = i;
                break;
            }
        }

        return (hi << 16) + low;
    }
};

int main() {
    Solution s;
    int missingInt = (1 << 16) + 2;

    int A[1 << 20];

    for (int i = 0; i < (1 << 20); i++) {
        A[i] = (i == missingInt) ? -1 : i;
    }

    int ret;
    ret = s.findMissingInteger(A, 1 << 20);
    cout << ret << endl;
}
