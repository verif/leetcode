/*
   Implement a function rotateArray(vector<int> arr, int r) which rotates the
   array by r places. Eg 1 2 3 4 5 on being rotated by 2 gives 4 5 1 2 3.
*/

#include <vector>
#include <iostream>

using namespace std;

// Solution is to use GCD to move the array in linear time using O(1) space
class RA {
public:
    int findGCD(int v1, int v2) {
        int gcd = 0;
        for (int i = 1; i <= v1 && i <= v2; i++) {
            if (v1 % i == 0 && v2 % i == 0) {
                if (gcd < i) gcd = i;
            }
        }
        return gcd;
    }

    void rotateArray(vector<int>& arr, int r) {
        int size = arr.size();
        r = r % size;
        if (!r) return;

        int d = findGCD(size, r);

        for (int i = 0; i < d; i++) {
            int next = (i+r) % size;
            int cur = i;
            int tmp = arr[cur];
            while (next != i) {
                int tmp2 = arr[next];
                arr[next] = tmp;
                cur = next;
                next = (next + r) % size;
                tmp = tmp2;
            }
            arr[next] = tmp;
        }
    }
};

int main() {
    RA ra;
    vector<int> arr = {1,2,3,4,5,6,7,8};

    ra.rotateArray(arr, 6);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
