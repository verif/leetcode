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
#define MAX_INT (1 << 32 - 1)
    typedef struct Line {
        double x_axis;
        double y_axis;
        double ratio;
        int totalPoints;
        Line() : x_axis(0), y_axis(0), ratio(0.0), totalPoints(0) {}
        Line(double a, double b, double r) : x_axis(a), y_axis(b), ratio(r),
        totalPoints(0) {}
    } Line;

    struct PointHashFunction {
        size_t operator() (const Point& p) const { return p.x;}
    };
    struct PointEqual {
        bool operator() (const Point &a, const Point& b)
            const { return (a.x == b.x && a.y == b.y); }
    };
    typedef struct LinePoints {
        unordered_map<Point, int, PointHashFunction, PointEqual> points;
    } LinePoints;

    struct LineHashFunction {
        size_t operator() (const Line* l) const { return l->x_axis;}
    };
    struct LineEqual {
        bool operator() (const Line *a, const Line *b)
            const { return (a->x_axis == b->x_axis && a->y_axis == b->y_axis &&
                            a->ratio == b->ratio); }
    };
public:
     int maxPoints(vector<Point> &points) {
         unordered_map<Point, int, PointHashFunction, PointEqual> samePoints;
         unordered_map<Line*, LinePoints*, LineHashFunction, LineEqual> lmap;
         Line* ln = NULL; 
         
         if (points.size() <= 2) return points.size();

         int iMax = 2;
         // Find the number of points in the same location
         for (vector<Point>::iterator i = points.begin(); i != points.end();
              i++) {
             if (samePoints.find(*i) != samePoints.end()) continue;
             int numPoints = 1;
             for (vector<Point>::iterator j = i+1; j != points.end(); j++) {
                 Point pt1 = *i;
                 Point pt2 = *j;
                 if (pt1.x == pt2.x && pt1.y == pt2.y) {
                     numPoints++;
                 }
             }
             iMax = iMax < numPoints ? numPoints : iMax;
             pair<Point, int> pr1(*i, numPoints);
             samePoints.insert(pr1);
         }

         for (vector<Point>::iterator i = points.begin(); i != points.end();
              i++) {
             for (vector<Point>::iterator j = i+1; j != points.end(); j++) {
                 Point p1 = *i;
                 Point p2 = *j;
                 if (p1.x == p2.x && p1.y == p2.y) {
                     continue;
                 }
                 double ratio = (p2.x == p1.x ? MAX_INT : (p2.y - p1.y) / ((p2.x - p1.x)*1.0));
                 double x_axis = (p1.x == p2.x) ? p2.x : ((p2.y == p1.y) ? MAX_INT : p2.x - p2.y/ratio);
                 double y_axis = (p1.y == p2.y) ? p1.y : ((p2.x == p1.x) ?  MAX_INT : p2.y - p2.x*ratio);

                 ln = new Line(x_axis, y_axis, ratio);

                 LinePoints *lp = NULL;

                 unordered_map<Point, int, PointHashFunction,
                    PointEqual>::iterator got3 = samePoints.find(p1);
                 unordered_map<Point, int, PointHashFunction,
                    PointEqual>::iterator got4 = samePoints.find(p2);
                 int numPoints1 = got3 == samePoints.end() ? 1 : got3->second;
                 int numPoints2 = got4 == samePoints.end() ? 1 : got4->second;

                 unordered_map<Line*, LinePoints*, LineHashFunction,
                 LineEqual>::iterator got = lmap.find(ln);
                 if (got == lmap.end()) {
                     lp = new LinePoints;
                     pair<Point, int> pair1(p1, 0);
                     pair<Point, int> pair2(p2, 0);
                     lp->points.insert(pair1);
                     lp->points.insert(pair2);
                     
                     pair<Line*, LinePoints*> pair3(ln, lp);
                     lmap.insert(pair3);
                     ln->totalPoints += (numPoints1+numPoints2);
                 }
                 else {
                     delete ln;

                     ln = got->first;
                     lp = got->second;
                     unordered_map<Point, int, PointHashFunction,
                        PointEqual>::iterator got1 = lp->points.find(p1);
                     if (got1 == lp->points.end()) {
                        pair<Point, int> pair1(p1, 0);
                        lp->points.insert(pair1);
                        ln->totalPoints += numPoints1;
                     }
                     unordered_map<Point, int, PointHashFunction,
                        PointEqual>::iterator got2 = lp->points.find(p2);
                     if (got2 == lp->points.end()) {
                        pair<Point, int> pair2(p2, 0);
                        lp->points.insert(pair2);
                        ln->totalPoints += numPoints2;
                     }
                 }
                 iMax = iMax < ln->totalPoints ? ln->totalPoints : iMax;
             }
         }

         return iMax;
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
