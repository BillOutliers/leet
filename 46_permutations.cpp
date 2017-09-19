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
�ο���http://blog.csdn.net/happyaaaaaaaaaaa/article/details/51534048
˼·��
    ȫ���У�����Ϊn������n!�����з���(���ظ�Ԫ��)��
	��һ����p = {r1, r2, r3, ... ,rn}, ȫ����Ϊperm(p)��pn = p - {rn}��
	���perm(p) = r1perm(p1), r2perm(p2), r3perm(p3), ... , rnperm(pn)��
	��n = 1ʱperm(p} = r1��Ϊ�˸�������⣬���������е����е����ֱ����һ����������
	�����������ڴ����n-1������ȫ���С�
	
	����DFS��������ȱ������ȹ̶���һ��Ԫ�أ�Ȼ������n-1��Ԫ�أ����õݹ鷽����
	���ý����ķ�����������ϡ�
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


