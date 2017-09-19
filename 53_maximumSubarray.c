
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

˼·��
    ���ö�̬�滮��numǰ�����ɸ����ĺ�Ϊdp����dp>=0,��dp����Ϊdp+num��
	����dpΪnum;Ȼ���ٸ���sumֵ��
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



