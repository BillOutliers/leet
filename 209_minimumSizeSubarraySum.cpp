
/*
Given an array of n positive integers and a positive integer s, find the minimal length of a 
contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
两指针问题，动态决定前后指针的位置
*/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0,start=0,end=0,minLen=INT_MAX;
		while(end< nums.size())
		{
			sum+=nums[end++];
			while(sum>=s)
			{
				minLen = min(minLen,end-start);
				sum-=nums[start++];
			}
		}
		return minLen==INT_MAX ? 0 : minLen;
    }
};


