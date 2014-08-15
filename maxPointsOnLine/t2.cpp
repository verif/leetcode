/*
   Given n points on a 2D plane, find the maximum number of points that lie on
   the same straight line.
*/

/**
   * Definition for a point.
   * struct Point {
   *     int x;
   *     int y;
   *     Point() : x(0), y(0) {}
   *     Point(int a, int b) : x(a), y(b) {}
   * };
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <assert.h>

using namespace std;

typedef struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
} Point;
class Solution {
public:
     typedef struct Line {
         double x_cross;
         double ratio;
         Line(double a, double b) : x_cross(a), ratio(b) {}
	 bool operator == (const Line* l1) {
	     return l1->x_cross == x_cross && l1->ratio == ratio;
	 }
         size_t hash() {
             return std::hash<double>()(x_cross);
         }
     } Line; 

     struct LineEqual {
         bool operator() (const Line* l1, const Line* l2) const {
             return l1->x_cross == l2->x_cross && l1->ratio == l2->ratio;
         }
     };

     struct LineHash {
         size_t operator() (const Line* l1) const {
             return l1->x_cross;
         }
     };

#define MAX_INT (1 << 32 - 1)
     int maxPoints(vector<Point> &points) {
         int total = points.size();
         if (total < 3) return total;
         int ret = 0;

         for (int i = 0; i < total; i++) {
             unordered_map<Line*, int, LineHash, LineEqual> lnMap;
             int max = 0;
             int same = 1;
             for (int j = i+1; j < total; j++) {
                 if (points[j].x == points[i].x && points[j].y == points[i].y) {
                     same++;
                     continue;
                 }
                 double ratio = (points[j].x == points[i].x) ? MAX_INT :
                  (points[j].y - points[i].y)*1.0 / (points[j].x - points[i].x);
                 double x_cross = points[j].x == points[i].x ? points[j].x :
                     (points[j].y == points[i].y ? MAX_INT : 
                                     points[i].x - points[i].y/ratio);
                 Line *l = new Line(x_cross, ratio);
                 lnMap[l]++;
                 max = max < lnMap[l] ? lnMap[l] : max;
             }
             max += same;
             ret = ret > max ? ret : max;
         }

         return ret;
     }
};

int main()
{
    Solution s;

    Point p1(0, 1);
    Point p2(-1, 0);
    Point p3(2, 3);
    Point p4(4, 5);
    Point p5(11, 11);
    Point p6 (1, 1);

    Point p7 (-1, -1);
    Point p9 (-3, -3);
    Point p8 (0, 0);
    Point p10(-1, 1);
    Point p11(2, -2);
    Point p12(1, -1);
    Point p13(0, 0);

    Point p14(1, 1);
    Point p15(0, 0);
    Point p16(0, 0);
    Point p17(0, 0);

    Point p18(1, 1);
    Point p19(1, 1);
    Point p20(1, 1);

    vector<Point> points;
    
    points.push_back(p18);
    points.push_back(p19);
    points.push_back(p20);
    /*
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);
    points.push_back(p6);
    */

    int ret = s.maxPoints(points);
    cout << "Max points is: " << ret << endl;
    
    points.push_back(p7);
    points.push_back(p9);
    points.push_back(p8);
    points.push_back(p10);
    points.push_back(p11);
    points.push_back(p12);

    // ret = s.maxPoints(points);
    // cout << "Max points is: " << ret << endl;

    points.push_back(p13);
    
    points.push_back(p14);
    points.push_back(p15);
    points.push_back(p16);
    points.push_back(p17);
    

    ret = s.maxPoints(points);
    cout << "Max points is: " << ret << endl;

    points.clear();
    Point pp1(84, 250);
    Point pp2(0, 0);
    Point pp3(1, 0);
    Point pp4(0, -70);
    Point pp5(0, -70);
    Point pp6(1, -1);
    Point pp7(21, 10);
    Point pp8(42, 90);
    Point pp9(-42, -230);
    points = {pp1, pp2, pp3, pp4, pp5, pp6,pp7, pp8, pp9};
    ret = s.maxPoints(points);
    cout << "Max points is: " << ret << endl;
}
