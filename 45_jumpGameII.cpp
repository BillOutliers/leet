/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

思路：
     使用两个标记变量记录每一步的跨度范围，start , end ;[start,end] ,在范围内再根据最大的
	 跨度更新start end的值；当到达目的时返回step。
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int len=nums.size();
		int start=0,end=0,step=0,maxEnd=0;
		while(end<len-1)
		{
			step++;
			for(int i=start;i<=end;i++)
			{
				if(i+nums[i]>=len-1) return step;
				maxEnd=max(maxEnd,i+nums[i]);
			}
			start=end+1;
			if(end==maxEnd) break;//不可到达
			end=maxEnd;
		}
		return len==1 ? 0 : -1;
    }
};
int main()
{
	Solution mys;
	vector<int> nums={0,1,3,2};//[2,3,1,1,4]
	// nums.push_back(2);
	// nums.push_back(3);
	// nums.push_back(1);
	// nums.push_back(1);
	// nums.push_back(4);
	cout<<mys.jump(nums)<<endl;
	return 0;
}


