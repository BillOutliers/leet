/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
思路：
    先升序排序
	多个数的累加和为target，考虑数据的重复使用，采用递归的方式进行累加
	
	
	c++11 编译时，老板编译器4.7
	g++ -std=c++0x  test.cpp
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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target){
        sort(candidates.begin(),candidates.end());
		vector<int> comb;
		vector<vector<int> > res;
		combination(candidates,comb,res,target,0);
		return res;
    }
private:
    void combination(vector<int> &candidates,vector<int> &comb,vector<vector<int> > &res,int target,int begin)
	{
		if(!target)
		{
			res.push_back(comb);
			return;
		}
		for(int i=begin;i<candidates.size() && target>=candidates[i];i++)
		{
			comb.push_back(candidates[i]);
			combination(candidates,comb,res,target-candidates[i],i);
			comb.pop_back();
		}
	}
};
int main()
{
    Solution mys;
	vector<std::vector<int> > res;
	vector<int> candidates;//={2,3,7};
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(7);
	int target=7;
	res=mys.combinationSum(candidates,target);
	for(int i=0;i<res.size();i++)
	{
	    for(int j=0;j<res[i].size();j++)
		    cout<<res[i][j];
		cout<<endl;
	}
	
		
    return 0;	
	
}


