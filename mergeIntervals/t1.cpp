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
        int len = intervals.size();
        if (!len) return intervals;
        
        std::sort(intervals.begin(), intervals.end(), mycmp());
        
        int i = 0, curEnd = 0;
        while (i < intervals.size()) { 
            int idx = i;
            curEnd = intervals[i].end;
            while(i < intervals.size() && intervals[i].start <= curEnd) {
                curEnd = std::max(curEnd, intervals[i].end);
                i++;
            };
            intervals[idx].end = curEnd;
            if (i > idx+1) intervals.erase(intervals.begin()+idx+1,
                                           intervals.begin()+i);
            i = idx + 1;
        }
        
        return intervals;
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
