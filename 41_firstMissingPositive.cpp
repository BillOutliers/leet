/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

思路：
    把每个数字放在正确的位置上，当数字小于数组长度len时。
	类似桶排序，数字3放在nums[2]的位置。
	对小于0与大于len的元素不进行处理。
	当调整完后，a[i]!=i+1时，出现第一个丢失的正整数,返回i+1
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
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
		for(int i=0;i<len;i++)
			while(nums[i]>0 && nums[i]<=len && nums[nums[i]-1]!=nums[i])
				swap(nums[i],nums[nums[i]-1]);
		for(int j=0;j<len;j++)
			if(nums[j]!=j+1)
				return j+1;
		return len+1;
    }
};
int main()
{
    Solution mys;
	vector<int> candidates;//={2,3,7};[10, 1, 2, 7, 6, 1, 5]
	candidates.push_back(1);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	int res=mys.firstMissingPositive(candidates);
	cout<<res<<endl;
		
    return 0;	
}



