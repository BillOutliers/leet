
/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
使用一个hash表对重复的数字计数，使用优先队列对hash中的计数值进行排序
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
private:
    struct bigger{
		bool operator()(pair<int,int> &a,pair<int,int>&b)
		{
			return a.first > b.first;
		}
	};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
		for(int i=0;i<nums.size();i++)
			mp[nums[i]]++;
		vector<int> res;
		priority_queue<pair<int,int>,vector<pair<int,int>>,bigger> p;//小顶堆
		for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(p.size()<k)
				p.push(make_pair(it->second,it->first));
			else if(it->second >= p.top().first)
			{
				p.pop();
				p.push(make_pair(it->second,it->first));
			}
		}
		while(!p.empty())
		{
			res.push_back(p.top().second);
			p.pop();
		}
		return res;
    }
};
int main()
{
	Solution mys;
	vector<int> nums={2,3,4,3,2,3};
	int k=2;
	vector<int>res=mys.topKFrequent(nums,k);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
	
	return 0;
}


	
	

