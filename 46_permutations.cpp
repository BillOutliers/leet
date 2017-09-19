/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
参考：http://blog.csdn.net/happyaaaaaaaaaaa/article/details/51534048
思路：
    全排列，长度为n的列有n!中排列方法(无重复元素)。
	设一组数p = {r1, r2, r3, ... ,rn}, 全排列为perm(p)，pn = p - {rn}。
	因此perm(p) = r1perm(p1), r2perm(p2), r3perm(p3), ... , rnperm(pn)。
	当n = 1时perm(p} = r1。为了更容易理解，将整组数中的所有的数分别与第一个数交换，
	这样就总是在处理后n-1个数的全排列。
	
	类似DFS，深度优先遍历，先固定第一个元素，然后排列n-1个元素，采用递归方法。
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >res;
		dfs(res,nums,0);
		return res;
    }
	 vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int> >res;
		sort(nums.begin(),nums.end());
		dfs2(res,nums,0);
		return res;
    }
	void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
private:
    void dfs(vector<vector<int> >&res,vector<int>&nums,int begin)
	{
		if(nums.size()==begin)
		{
			res.push_back(nums);
			return;
		}
		for(int i=begin;i<nums.size();i++)
		{
			swap(nums[i],nums[begin]);
			dfs(res,nums,begin+1);
			swap(nums[i],nums[begin]);
		}
	}
	void dfs2(vector<vector<int> > &res,vector<int> nums,int begin)
	{
		if(begin==nums.size()-1)
		{
			res.push_back(nums);
			return;
		}
		for(int i=begin;i<nums.size();i++)
		{
			if(i!=begin && nums[i]==nums[begin]) continue;
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


