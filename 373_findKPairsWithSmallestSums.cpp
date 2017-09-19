
/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
遍历每种组成(min(nums1.size(),k)*min(nums2.size(),k)种)
构建大顶堆，如果比大顶堆的第一个小，就把大顶堆pop一个节点，把新节点加入；
*/


class Solution {
private:
    struct cmp{
		bool operator()(pair<int,int>&a,pair<int,int>&b){
			return a.first+a.second < b.first+b.second;
		}
	};
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
		if(nums1.empty() || nums2.empty() || k<=0) return res;
		priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;//大顶堆
		for(int i=0;i<min((int)nums1.size(),k);i++)
			for(int j=0;j<min((int)nums2.size(),k);j++)
			{
				if(pq.size()<k)
					pq.push(make_pair(nums1[i],nums2[j]));
				else if(nums1[i]+nums2[j] < pq.top().first+pq.top().second)
				{
					pq.pop();
					pq.push(make_pair(nums1[i],nums2[j]));
				}
			}
		while(!pq.empty())
		{
			res.push_back(pq.top());
			pq.pop();
		}
		return res;
    }
};


