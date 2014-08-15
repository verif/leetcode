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
    int findInsertLocation(vector<Interval> &intervals, Interval newInterval) {
        int start = 0, end = intervals.size()-1;
        int mid = (start+end)/2;
        if (intervals[0].start > newInterval.start) return -1;
        if (intervals.back().start < newInterval.start) return
intervals.size()-1;
        
        while (start < end) {
            if (intervals[mid].start == newInterval.start) return mid;
            else if (intervals[mid].start < newInterval.start) start = mid+1;
            else end = mid-1;
            mid = (start+end)/2;
        }
        
        return intervals[mid].start < newInterval.start ? mid : mid-1;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (!intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int idx = findInsertLocation(intervals, newInterval);
        int newStart = idx < 0 || intervals[idx].end < newInterval.start ?
newInterval.start : intervals[idx].start;
        int st = idx < 0 || intervals[idx].end < newInterval.start ? idx+1 :
idx;
        int ed = 0;
        int newEnd = newInterval.end;
        for (ed = std::max(idx, 0); ed < intervals.size(); ed++) {
            if (newEnd >= intervals[ed].start) {
                newEnd = std::max(newEnd, intervals[ed].end);
            }
            else break;
        }
        
        if (ed >= st+1) intervals.erase(intervals.begin()+st,
intervals.begin()+ed);
        newInterval.start = newStart;
        newInterval.end = newEnd;
        intervals.insert(intervals.begin()+st, newInterval);
        
        return intervals;
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

