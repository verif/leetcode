/*
   Write an efficient program for printing k largest elements in an array.
   Elements in array can be in any order.
*/

#include <algorithm> // 'swap'/'make_heap'/'push_heap'/'pop_heap'/'sort_heap'
#include <queue> 
#include <iostream>

class InsertionSort {
public:
    // complexity: n*n
    std::vector<int> findKLargestElementsInArray(int A[], int n, int k) {
        std::vector<int> ret;
        if (!k || !n || k > n) return ret;
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (A[j+1] >= A[j]) break;
                std::swap(A[j+1], A[j]);
            }
        }

        for (int i = 0; i < k; i++) ret.push_back(A[n-i-1]);

        return ret;
    }
};

class BubbleSort {
public:
    // complexity: k*n
    std::vector<int> findKLargestElementsInArray(int A[], int n, int k) {
        std::vector<int> ret;
        if (!k || !n || k > n) return ret;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (A[j] > A[j+1]) std::swap(A[j], A[j+1]);
            }
            ret.push_back(A[n-i-1]);
        }
        return ret;
    }
};

class PriorityQ {
public:
    struct mycmp {
        bool operator() (int l, int r) {
            return l > r;
        }
    };
    // complexity: n*logk
    std::vector<int> findKLargestElementsInArray(int A[], int n, int k) {
        std::vector<int> ret;
        if (!k || !n || k > n) return ret;

        std::priority_queue<int, std::vector<int>, mycmp> q;
        for (int i = 0; i < k; i++) q.push(A[i]);

        for (int i = k; i < n; i++) {
            if (A[i] > q.top()) {
                q.pop();
                q.push(A[i]);
            }
        }

        while (!q.empty()) {
            ret.push_back(q.top());
            q.pop();
        }

        return ret;
    }
};

class MinHeap {
public:
    struct mycmp {
        bool operator() (int l, int r) {
            return l > r;
        }
    };
    std::vector<int> findKLargestElementsInArray(int A[], int n, int k) {
        std::vector<int> ret;
        if (!k || !n || k > n) return ret;

        for (int i = 0; i < k; i++) ret.push_back(A[i]);
        std::make_heap(ret.begin(), ret.end(), mycmp());

        for (int i = k; i < n; i++) {
            if (A[i] > ret[0]) {
                std::pop_heap(ret.begin(), ret.end(), mycmp());
                ret.resize(ret.size()-1);
                ret.push_back(A[i]);
                std::push_heap(ret.begin(), ret.end(), mycmp());
            }
        }
        return ret;
    }
};

int main() {
    BubbleSort b;
    InsertionSort ist;
    PriorityQ pq;
    MinHeap mh;

    int A[10] = {1, 20, 3, 54, 4522, 224, 234, 0, -1, 24};
    std::vector<int> ret;
    
    ret = b.findKLargestElementsInArray(A, 10, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << ret[i] << std::endl;
    }
    std::cout << std::endl;

    ret = ist.findKLargestElementsInArray(A, 10, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << ret[i] << std::endl;
    }
    std::cout << std::endl;

    ret = pq.findKLargestElementsInArray(A, 10, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << ret[i] << std::endl;
    }
    std::cout << std::endl;

    ret = mh.findKLargestElementsInArray(A, 10, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << ret[i] << std::endl;
    }
    std::cout << std::endl;
}
