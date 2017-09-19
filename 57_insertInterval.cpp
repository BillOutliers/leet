/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
找插入元素的左右边界位置
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
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
		int l = -1,r = n;
		while(l < n-1 && intervals[l+1].end < newInterval.start) 
		{
			l++;
		}
		while(r > 0 && intervals[r-1].start > newInterval.end) 
		{
			r--;
		}
		if(r > 0) newInterval.end = max(newInterval.end,intervals[r-1].end);
		if(l < n-1) newInterval.start = min(newInterval.start,intervals[l+1].start);
		vector<Interval> res;
		for(int i=0;i<=l;i++)
			res.push_back(intervals[i]);
		res.push_back(newInterval);
		for(int i = r;i < n;i++)
			res.push_back(intervals[i]);
		return res;
    }
};
int main()
{
	Solution mys;
	vector<Interval> intervals={Interval(1,3),Interval(6,9)};
	Interval val(2,5);
	vector<Interval> res=mys.insert(intervals,val);
	
	return 0;
}


