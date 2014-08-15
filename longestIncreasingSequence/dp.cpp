/*
   Find the longest increasing sequence from input int array 
*/

#include <iostream>
#include <algorithm> // for std::max

// dynamic programming with time complexity n*n
class A {
public:
int findLongestIncreasingSequence(int A[], int n) {
    if (n < 2) return n;
    int res[n];
    int ret = 0;

    res[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        int max = 0;
        for (int j = i+1; j < n; j++) {
            if (A[i] < A[j]) {
                max = std::max(max, res[j]+1);
            }
        }
        res[i] = max;
        ret = std::max(ret, max);
    }
    return ret;
}
};

int main() {
    A a;
    int ret;

    int A[] = {3, 5, 1, 2, 9, 7, 2, 3, 4, 6};
    ret = a.findLongestIncreasingSequence(A, 10);
    std::cout << "Expected: 5, Actual: " << ret << std::endl;
}
