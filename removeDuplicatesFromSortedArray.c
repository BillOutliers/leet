
/*
Given a sorted array, remove the duplicates in place such that each element
 appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums
being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
	if(numsSize<=1) return numsSize;
    int *f=nums+1;
    int *low=nums;
    while(f<nums+numsSize)    
	{
		//printf("f:%d\n",*f);
		while(f<nums+numsSize && *f == *(f-1))f++;
		*++low=*f;
		f++;
	}
	return numsSize-(f-low)+1;
}
int removeElement(int* nums, int numsSize, int val)
{
	int *f=nums;
	int *low=nums;
	while(f<nums+numsSize)
	{
		while(f<nums+numsSize && val==*f) f++;
		*low++=*f++;
	}
	return numsSize-(f-low);
}
int main()
{
	int arr[]={};
	int len=sizeof(arr)/sizeof(int);
	// int len_new=removeDuplicates(arr,len);
	int len_new=removeElement(arr,len,2);
	printf("%d\n",len_new);
	int i=0;
	for(;i<len_new;i++)
		printf("%d\n",arr[i]);
	return 0;
}