/* 
 * Given an array A of integers, find the maximum of j-i subjected to the
 * constraint of A[i] < A[j].
 */

#include <iostream>
#include <assert.h>
using namespace std;

int findMaxDistance(int* arr, int size)
{
    assert(size > 0);

    int* validStartArr = new int [size];
    int i;
    int min = arr[0] + 1;

    // Find all valid starting points
    int idx = 0;
    for (i = 0; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
            validStartArr[idx] = i;
            idx++;
        }
    }

    // Now find valid ending points and compute max distance
    int lastEnd = size - 1;
    int maxDistance = 0;
    for (i = idx - 1; i >= 0; i--) {
        for (int j = lastEnd; j >= validStartArr[i]; j--) {
            if (arr[j] > arr[validStartArr[i]]) {
                if (maxDistance < j - validStartArr[i]) {
                    maxDistance = j - validStartArr[i];
                    cout << "Find new max distance: " << maxDistance <<
                        " from index " <<
                        validStartArr[i] << " to index " << j << endl;
                }
                lastEnd = j;
                break;
            }
        }
    }

    return maxDistance;
}

int main()
{
    int* arr;
    int size;

    while (1) {
        cout << "Please input array size: " << endl;
        cin >> size;
        assert(size > 0);
        arr = new int [size];
        cout << "Please input array elements: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        int maxDistance = findMaxDistance(arr, size);
        cout << "Max distance for input array is: " << maxDistance << endl;
    }
}
