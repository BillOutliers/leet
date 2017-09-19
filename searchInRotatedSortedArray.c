/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you
 beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, 
otherwise return -1.
You may assume no duplicate exists in the array.

˼·��
    1.ʹ�ö��ַ��ҵ����ֵ����Сֵ������ ����¼��Сֵ������Ϊstart
	2.������[0,start)�뿪���������Ϊ������ ��[start,numsSize-1]������Ϊ������
	3.�ٴ�ʹ�ö��ֲ����ҵ�targetֵ

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
		realmid=(mid+start)%numsSize;//��startΪ�����������㣬Ѱ�����������ĵ�
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
