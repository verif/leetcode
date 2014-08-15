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
     vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
         vector<Interval> ret;
         if (!intervals.size()) {
             ret.push_back(newInterval);
             return ret;
         }
        
         // find where it should be inserted
         vector<Interval>::iterator i = intervals.begin();
         int start = 0;
         int end = intervals.size()-1;
         int mid = (start+end)/2;
         int s = newInterval.start;
         int e = newInterval.end;
         while (mid >= start && mid <= end) {
             if (intervals[mid].start > e) {
                 end = mid-1;
                 mid = (start+end)/2;
             }
             else if (intervals[mid].end < s) {
                 start = mid+1;
                 mid = (start+end)/2;
             }
             else {
                 break;
             }
         }

         // overlapping
         if (intervals[mid].start <= e && intervals[mid].end >= s) {
             start = mid; 
             end = mid;
             while (start >= 0 && intervals[start].end >= s) {
                 start--;
             }
             while (end < intervals.size() && intervals[end].start <= e) {
                 end++;
             }
             int min = intervals[start+1].start > s ? s :
                 intervals[start+1].start;
             int max = intervals[end-1].end > e ? intervals[end-1].end : e;
             intervals.erase(intervals.begin()+start+1,
                             intervals.begin()+end);
             Interval iv(min, max);
             intervals.insert(intervals.begin()+start+1, iv);
         }
         else {
             if (intervals[mid].start > e) {
                intervals.insert(intervals.begin()+mid, newInterval);
             }
             else {
                intervals.insert(intervals.begin()+mid+1, newInterval);
             }
         }

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

