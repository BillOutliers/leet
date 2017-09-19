

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int *start=nums,*fast=nums;
	while(fast < nums+numsSize)
	{
		while(fast < nums+numsSize && *fast == 0) fast++;
		*start++=*fast++;
	}
	while(start < nums+numsSize)
		*start++=0;
}
int main()
{
	int nums[]={0,0};
	int numsSize=sizeof(nums)/sizeof(int);
	moveZeroes(nums,numsSize);
	int i=0;
	for(;i<numsSize;i++)
		printf("%d\n",nums[i]);
	return 0;
}
