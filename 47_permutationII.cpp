/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
˼·��
    ����Ѱ����һ���е�˼·������������Ȼ�������ҳ��������������С�
	����DFS��������ȱ������ȹ̶���һ��Ԫ�أ�Ȼ������n-1��Ԫ�أ����õݹ鷽��(ע�������ظ�������)��
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
	 vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int> >res;
		sort(nums.begin(),nums.end());//����
		dfs2(res,nums,0);
		return res;
	 }
private:
    //nums ͨ��������ʽ����ÿ�ν�����Ԫ�غ�Ž�����ȥ����֤�ֲ�����
	void dfs2(vector<vector<int> > &res,vector<int> &nums,int begin)
	{
		if(begin==nums.size()-1)
		{
			res.push_back(nums);
			return;
		}
		for(int i=begin;i<nums.size();i++)//Ѱ����һ�������������
		{
			if(i!=begin && nums[i]==nums[begin]) continue;//�����ظ�ֵ
			swap(nums[begin],nums[i]);
			dfs2(res,nums,begin+1);
			swap(nums[begin],nums[i]);
		}
	}
    //��ͨ��������ʽ
	void dfs(vector<vector<int> > &res,vector<int> nums,int begin)
	{
		if(begin==nums.size()-1)
		{
			res.push_back(nums);
			return;
		}
		for(int i=begin;i<nums.size();i++)//Ѱ����һ�������������
		{
			if(i!=begin && nums[i]==nums[begin]) continue;//�����ظ�ֵ
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


