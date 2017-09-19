
/*

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
采用dfs方法来寻找各个子集合
*/




class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> res;
		 vector<int>tmp;
         dfs(res,tmp,nums,0);
		 return res;
    }
	void dfs(vector<vector<int>>&res,vector<int>&tmp,vector<int>& nums,int start)
	{
		res.push_back(tmp);
		for(int i=start;i<nums.size();i++)
		{
			tmp.push_back(nums[i]);
			dfs(res,tmp,nums,i+1);
			tmp.pop_back();
		}
	}
};

