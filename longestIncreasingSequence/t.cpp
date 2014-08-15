/*
   Find the longest increasing sequence from input int array 
*/

#include <iostream>
#include <algorithm> // for std::max
#include <climits> 

// dynamic programming, with helping array, with time complexity n*log(n)
// Idea is: on top of dynamic programming, use an array to remember the max
// start value of the increasing sequence, e.g., mx[n], where mx[k] is the 
// largest starting number of all the 'k' length increasing sequences.

class A {
public:
 // mx is sorted from large to small
 int findInsertIndex(int mx[], int end, int v) {
     int start = 0;
     int mid = end/2;
     while (start <= end) {
         if (mx[mid] == v) {
             return mid;
         }
         else if (mx[mid] < v) {
             end = mid-1;
         }
         else {
             start = mid+1;
         }
         mid = (start+end)/2;
     }
     return mx[mid] <= v || mid == end ? mid : mid+1;
 }

 int findLongestIncreasingSequence(int A[], int n) {
    if (n < 2) return n;
    int maxStarting[n+1]; // sorted array for max starting
    int ret = 1;

    maxStarting[0] = INT_MAX;
    maxStarting[1] = A[n-1];

    for (int i = n-2; i >= 0; i--) {
        if (A[i] < maxStarting[ret]) {
            maxStarting[++ret] = A[i];
        }
        else {
            int idx = findInsertIndex(maxStarting, ret, A[i]); 
            maxStarting[idx] = A[i];
        }
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
