/*
Given an m*n matrix with all its elments=1. Also given a list of (x,y)
points. The question was to make the elements of xth row and yth column as
zero. Optimise it.
*/

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

typedef struct Point {
    int x;
    int y;
    Point(int xval, int yval) : x(xval), y(yval) {}
} Point;

class Solution {
public:
    void setMatrixZeros(vector<vector<int>>& matrix, vector<Point*> points) {
        unordered_set<int> xsets, ysets;
        if (!matrix.size()) return;

        for (int i = 0; i < points.size(); i++) {
            xsets.insert(points[i]->x);
            ysets.insert(points[i]->y);
        }

        unordered_set<int>::const_iterator it;
        for (it = xsets.begin(); it != xsets.end(); it++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                matrix[*it][col] = 0;
            }
        }
        for (it = ysets.begin(); it != ysets.end(); it++) {
            for (int row = 0; row < matrix.size(); row++) {
                matrix[row][*it] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix(6, vector<int>(6, 1));

    Point p1(2, 3);
    Point p2(4, 5);
    Point p3(1, 0);

    vector<Point*> pts = {&p1, &p2, &p3};

    s.setMatrixZeros(matrix, pts);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
}
