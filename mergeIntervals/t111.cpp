/*
   Given a collection of intervals, merge all overlapping intervals.

   For example,
   Given [1,3],[2,6],[8,10],[15,18],
   return [1,6],[8,10],[15,18]
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
   * Definition for an interval.
    * struct Interval {
    *     int start;
    *     int end;
    *     Interval() : start(0), end(0) {}
    *     Interval(int s, int e) : start(s), end(e) {}
    * };
*/
typedef struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
} Interval;

class Solution {
public:
    struct mycmp {
        bool operator () (const Interval& l, const Interval& r) {
            return l.start < r.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (!intervals.size()) return res;

        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = std::max(res.back().end, intervals[i].end);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<Interval> ret;
    vector<Interval> intervals;

    Interval i11(2, 3);
    Interval i21(5, 5);
    Interval i3(2, 2);
    Interval i4(3, 4);
    Interval i5(4, 4);
    intervals.push_back(i11);intervals.push_back(i21);
    intervals.push_back(i3);intervals.push_back(i4);intervals.push_back(i5);
    ret = s.merge(intervals);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;
}
