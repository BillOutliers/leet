/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
		vector<vector<int> >res;
		vector<int>tmp;
		dfs(res,nums,tmp,0);
		return res;
    }
	void dfs(vector<vector<int> >& res,vector<int>& nums,vector<int>& tmp,int begin)
	{
		res.push_back(tmp);
		for(int i=begin;i<nums.size();i++)
		{
			if(i==begin || nums[i]!=nums[i-1])//Ìø¹ýÖØ¸´ÔªËØ
			{
				tmp.push_back(nums[i]);
				dfs(res,nums,tmp,i+1);
				tmp.pop_back();
			}
		}
	}
};



