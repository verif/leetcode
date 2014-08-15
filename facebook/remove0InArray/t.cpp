/*
   Given an array of integers, now we want to erase all 0s (can be other
   value), and we want the result array condensed, meaning no empty cell in the
   array
*/

#include <iostream>

class RemoveZero {
public:
    int removeZeroInArray(int A[], int len) {
        if (!len) return 0;
        int st = 0, idx = 0;

        while (st < len && A[st] != 0) st++;
        idx = st;
        while (idx < len) {
            while (idx < len && A[idx] == 0) idx++;
            if (idx >= len) break;
            while (st < idx && idx < len && A[idx]) {
                A[st++] = A[idx++];
            }
        }

        return st;
    }
};

int main() {
    RemoveZero rz;

    int A[] = {0, 0, 1, 2, 0, 3, 0, 0, 4, 5, 0, 0, 0, 6, 0, 0, 0, 0};

    int size = rz.removeZeroInArray(A, 18);

    for (int i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
