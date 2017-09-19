
/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
思路：
    升序排序
    必须跳过重复的组合
	采用递归来寻找组合
	
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
        sort(candidates.begin(),candidates.end());
		vector<vector<int> >res;
		vector<int> combination;
		combinationS(res,candidates,combination,target,0);
		return res;
    }
private:
    void combinationS(vector<vector<int> > &res,vector<int> &candidates,vector<int> &combination,int target,int begin)
	{
		if(!target)
		{
			res.push_back(combination);
			return;
		}
		else{
			for(int i=begin;i<candidates.size() && candidates[i]<=target;i++)
			{
				if(i && candidates[i]==candidates[i-1] && i>begin) continue;//跳过重复部分
				combination.push_back(candidates[i]);
				combinationS(res,candidates,combination,target-candidates[i],i+1);
				combination.pop_back();
			}
		}
	}
};
int main()
{
    Solution mys;
	vector<std::vector<int> > res;
	vector<int> candidates;//={2,3,7};[10, 1, 2, 7, 6, 1, 5]
	candidates.push_back(1);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	int target=8;
	res=mys.combinationSum2(candidates,target);
	for(int i=0;i<res.size();i++)
	{
	    for(int j=0;j<res[i].size();j++)
		    cout<<res[i][j];
		cout<<endl;
	}
	
		
    return 0;	
}






