
/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.


*/

bool canJump(int* nums, int numsSize) {
    if(!nums) return 1;
	int end=0,start=0,maxend=0, i=0;
	while(end < numsSize-1)
	{
		for(i=start;i<=end;i++)
		{
			if(i+nums[i]>=numsSize-1) return 1;
			maxend = maxend < i+nums[i] ? i+nums[i] : maxend;
		}
		start=end+1;
		if(end == maxend) return 0;//²»¿É´ï
		end=maxend;
	}
	return 1;
}


