/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
思路：
    按照寻找下一序列的思路，先升序排序，然后依次找出逐渐增大的组合序列。
	类似DFS，深度优先遍历，先固定第一个元素，然后排列n-1个元素，采用递归方法(注意跳过重复的排列)。
	采用交换的方法来排列组合。
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	 vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int> >res;
		sort(nums.begin(),nums.end());//升序
		dfs2(res,nums,0);
		return res;
	 }
private:
    //nums 通过引用形式，，每次交换完元素后才交换回去，保证局部递增
	void dfs2(vector<vector<int> > &res,vector<int> &nums,int begin)
	{
		if(begin==nums.size()-1)
		{
			res.push_back(nums);
			return;
		}
		for(int i=begin;i<nums.size();i++)//寻找下一个递增序列组合
		{
			if(i!=begin && nums[i]==nums[begin]) continue;//跳过重复值
			swap(nums[begin],nums[i]);
			dfs2(res,nums,begin+1);
			swap(nums[begin],nums[i]);
		}
	}
    //不通过引用形式
	void dfs(vector<vector<int> > &res,vector<int> nums,int begin)
	{
		if(begin==nums.size()-1)
		{
			res.push_back(nums);
			return;
		}
		for(int i=begin;i<nums.size();i++)//寻找下一个递增序列组合
		{
			if(i!=begin && nums[i]==nums[begin]) continue;//跳过重复值
			swap(nums[begin],nums[i]);
			dfs2(res,nums,begin+1);
		}
	}
};
int main()
{
    Solution mys;
	vector<std::vector<int> > res;
	vector<int> nums={1,2,3};
	res=mys.permute2(nums);
	for(int i=0;i<res.size();i++)
	{
	    for(int j=0;j<res[i].size();j++)
		    cout<<res[i][j];
		cout<<endl;
	}
	
		
    return 0;	
}


