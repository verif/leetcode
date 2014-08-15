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
     static bool mycmp(const Interval &i1, const Interval &i2) {
         return (i1.start < i2.start);
     }
     vector<Interval> merge(vector<Interval> &intervals) {
         if (intervals.size() < 2) return intervals;

         sort(intervals.begin(), intervals.end(), Solution::mycmp);
         vector<Interval>::iterator it = intervals.begin();
         while (it != intervals.end()) {
             vector<Interval>::iterator nit = it+1;
             if (nit == intervals.end()) break;
             Interval iv = *it;
             Interval niv = *nit;
             if (iv.end < niv.start) {
                 it++;
                 continue;
             }
             int mi = min(iv.start, niv.start);
             int ma = max(iv.end, niv.end);
             while (nit != intervals.end()) {
                 niv = *nit;
                 if (niv.start > ma) break;
                 ma = max(niv.end, ma);
                 nit++;
             }
             // Merge current two
             Interval iv2(mi, ma);
             it = intervals.erase(it, nit);
             it = intervals.insert(it, iv2);
         }
         return intervals;
     }
};

int main()
{
    Solution s;
    vector<Interval> ret;
    vector<Interval> intervals;

    Interval i11(1, 3);
    Interval i21(2, 6);
    Interval i3(8, 10);
    Interval i4(15, 18);
    Interval i5(15, 16);
    intervals.push_back(i11);intervals.push_back(i21);
    intervals.push_back(i3);intervals.push_back(i4);intervals.push_back(i5);
    ret = s.merge(intervals);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i].start <<"," << ret[i].end << "]" << ",";
    }
    cout << endl;
}
