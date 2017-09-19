
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
思路：
     先按照集合中个区间的左边界的大小排序，升序；
	 若 i<j,i、j为第几个区间，则
		i.start<=j.start 
		若 i.end >= j.start 则合并为[i.start,j.end]
		若 i.end < j.start 则不合并，把区间添加到集合中
		重复以上步骤
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
class Solution {
public:
	static bool comp(Interval x,Interval y)
	{
		return x.start < y.start || (x.start==y.start && x.end < y.end);
	}
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
		int n= intervals.size();
		if(n==0) return res;
		sort(intervals.begin(),intervals.end(),Solution::comp);
		int start = intervals[0].start,end= intervals[0].end;
		for(int i=1;i<n;i++)
		{
			if(end >= intervals[i].start)//区间重合
				end = end < intervals[i].end ? intervals[i].end : end;
			else
			{
				res.push_back(Interval(start,end));//记录区间
				start=intervals[i].start;
				end=intervals[i].end;
			}
		}
		res.push_back(Interval(start,end));//记录最后一个区间
		return res;
    }
};







