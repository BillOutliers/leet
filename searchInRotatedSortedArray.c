/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you
 beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, 
otherwise return -1.
You may assume no duplicate exists in the array.

思路：
    1.使用二分法找到最大值与最小值跳变沿 ，记录最小值的索引为start
	2.在索引[0,start)半开半闭区间内为增序列 在[start,numsSize-1]区间内为增序列
	3.再次使用二分查找找到target值

*/

#include <stdio.h>
int search(int* nums, int numsSize, int target){
    if(numsSize==0)
		return -1;
	int mid=0,left=0,right=numsSize-1;
	while(left<right)
	{
		mid=(left+right)>>1;
		if(nums[mid]>=nums[right])
			left=mid+1;
		else
			right=mid;
	}
	int start=left;
	left=0,right=numsSize-1;
	int realmid=0;
	while(left<=right)
	{
		mid=(left+right)>>1;
		realmid=(mid+start)%numsSize;//以start为升序数组的起点，寻找真正的中心点
		if(nums[realmid]==target) return realmid;
		if(nums[realmid]<target) left=mid+1;
		else right=mid-1;
	}
	return -1;
}
int search2(int* nums, int numsSize, int target){
    if(numsSize==0)
		return -1;
	int mid=0,left=0,right=numsSize-1;
	while(left<right)
	{
		mid=(left+right)>>1;
		if(nums[mid]>=nums[right])
			left=mid+1;
		else
			right=mid;
	}
	int start=left;
	left= target<=nums[numsSize-1] ? start : 0;
	right= target>nums[numsSize-1] ? start-1 : numsSize-1;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(nums[mid]==target) return mid;
		if(nums[mid]<target) left=mid+1;
		else right=mid-1;
	}
	return -1;
}
int main()
{
	int arr[]={4,5,6,7,0,1,2};
	int len=sizeof(arr)/sizeof(int);
	printf("%d\n",search2(arr,len,5));
	
	return 0;
}
