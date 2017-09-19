
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

思路：
    采用动态规划，num前面若干个数的和为dp，若dp>=0,则dp更新为dp+num，
	否则dp为num;然后再更新sum值。
*/


int maxSubArray(int* nums, int numsSize) {
    int sum=nums[0],dp=nums[0];
	int *num=nums+1;
	for(;num<nums+numsSize;num++)
	{
		dp = *num < (dp+ *num) ? (dp+ *num) :  *num ;
		sum = sum < dp ? dp : sum;
	}
	return sum;
}



