/*
Given an array of integers sorted in ascending order, find the starting and ending position of 
a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

思路：
    使用二分法找到目标值的左边界
	使用二分法找到目标值的右边界
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	*returnSize=2;
	int *res=(int *)malloc(2*sizeof(int));
	res[0]=-1;
	res[1]=-1;
	int left=0,right=numsSize-1,mid=0;
	while(left<right)
	{
		mid=(left+right)>>1;
		if(nums[mid]<target) left=mid+1;
		else right=mid;
	}
	if(nums[left]!=target)
		return res;
	else
		res[0]=left;   //存储左边界
	right=numsSize-1;
	while(left<right)
	{
		mid=(left+right + 1)/2;
		if(nums[mid]>target) right=mid-1;
		else left=mid;
	}
	res[1]=right;   //存储右边界
	return res;
}
/*
Given a sorted array and a target value, return the index if the target is found. If not, return 
the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
思路：
    使用二分法查找
	当target不存在与数组中时，以left索引来标注该值在数组中的排序索引。
*/
int searchInsert(int* nums, int numsSize, int target)
{
	int left=0,right=numsSize-1,mid=0;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(nums[mid]==target) return mid;
		else if(nums[mid]>target) right=mid-1;
		else left=mid+1;
	}
	return left;
}

int main(int argc,char **argv)
{
	int array[]={5, 7, 8, 10};
	int numsSize=sizeof(array)/sizeof(int);
	int returnSize=0;
	int target=12;
	// int *p=searchRange(array,numsSize,target,&returnSize);
	// int i=0;
	// for(;i<returnSize;i++)
		// printf("%d\n",p[i]);
    printf("%d\n",searchInsert(array,numsSize,target));
	return 0;
}


