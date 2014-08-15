#include <iostream>

using namespace std;

const int MAX_N = 100;

int findMax(int A[], int n, int k) {
    int M[MAX_N+1][MAX_N+1] = {0};
    int i, j;
    int i1;
    int cum[MAX_N+1] = {0};
    int min = MAX_N;

    for (i = 1; i <= n; i++) {
        cum[i] = cum[i-1] + A[i-1];
    }
    for (i = 1; i <= n; i++) {
        M[i][1] = cum[i];
    }

    for (i = 1; i < k; i++) {
        M[1][i] = A[0];
    }

    for (i = 2; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            int curMin = MAX_N;
            for (i1 = j-1; i1 < i; i1++) {
                int min;
                if (M[i1][j-1] > (cum[i] - cum[i1])) {
                    min = M[i1][j-1];
                }
                else {
                    min = cum[i] - cum[i1];
                } 
                // int min = M[i1][j-1] < (cum[i] - cum[i1]) ? M[i1][j-1] : (cum[i] - cum[i1]);
                curMin = curMin > min ? min : curMin;
            }
            M[i][j] = curMin;
        }
    }

    return M[n][k];
}

int main()
{
    int n, k;
    int A[MAX_N];
    while (1) {
        cout << "Please input number of boards: " << endl;
        cin >> n;
        cout << "Please input number of painters: " << endl;
        cin >> k;
        cout << "Please input " << n << " of board lengths" << endl;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int ret = findMax(A, n, k);
        cout << "Max time is " << ret << endl;
    }
}
