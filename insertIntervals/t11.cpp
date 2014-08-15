/*
   Given a set of non-overlapping intervals, insert a new interval into the
   intervals (merge if necessary).
   You may assume that the intervals were initially sorted according to their
   start times.

   Example 1:
   Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

   Example 2:
   Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
   [1,2],[3,10],[12,16].
   This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
   * Definition for an interval.
   * struct Interval {
   *     int start;
   *     int end;
   *     Interval() : start(0), end(0) {}
   *     Interval(int s, int e) : start(s), end(e) {}
   * };
*/

#include <vector>
#include <iostream>
using namespace std;

typedef struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
} Interval;

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
        vector<Interval> res;

        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (newInterval.start < intervals[i].start) {
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
        }
        if (i == intervals.size()) intervals.push_back(newInterval);
        
        // Now merge potential overlapping intervals
        res.push_back(intervals[0]);
        for (i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= res.back().end) {
                res.back().end = std::max(intervals[i].end, res.back().end);
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
    Interval newInterval(2,5);

    Interval i1(1, 3);
    Interval i2(6, 9);
    intervals.push_back(i1);intervals.push_back(i2);
    //ret = s.insert(intervals, newInterval);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;

    intervals.clear();
    Interval i11(1, 2);
    Interval i21(3, 5);
    Interval i3(6, 7);
    Interval i4(8, 10);
    Interval i5(12, 16);
    intervals.push_back(i11);intervals.push_back(i21);
    intervals.push_back(i3);intervals.push_back(i4);intervals.push_back(i5);
    newInterval.start = 4;
    newInterval.end = 9;
    ret = s.insert(intervals, newInterval);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;

    newInterval.start = -2;
    newInterval.end = -1;
    ret = s.insert(intervals, newInterval);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;

    newInterval.start = 24;
    newInterval.end = 29;
    ret = s.insert(intervals, newInterval);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;

    newInterval.start = 11;
    newInterval.end = 12;
    ret = s.insert(intervals, newInterval);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;

    intervals.clear();
    i11.end = 5;
    intervals.push_back(i11);
    newInterval.start = 2;
    newInterval.end = 3;
    ret = s.insert(intervals, newInterval);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;
}

