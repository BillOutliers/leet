
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
˼·��
     �Ȱ��ռ����и��������߽�Ĵ�С��������
	 �� i<j,i��jΪ�ڼ������䣬��
		i.start<=j.start 
		�� i.end >= j.start ��ϲ�Ϊ[i.start,j.end]
		�� i.end < j.start �򲻺ϲ�����������ӵ�������
		�ظ����ϲ���
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
			if(end >= intervals[i].start)//�����غ�
				end = end < intervals[i].end ? intervals[i].end : end;
			else
			{
				res.push_back(Interval(start,end));//��¼����
				start=intervals[i].start;
				end=intervals[i].end;
			}
		}
		res.push_back(Interval(start,end));//��¼���һ������
		return res;
    }
};







