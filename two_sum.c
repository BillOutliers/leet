/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *p = (int *)malloc(2*sizeof(int));
    int i=0;
    int j=0;
    int cha=0;
    for(i=0;i < numsSize-1;i++)
    {
        cha=target-nums[i];
        j=i+1;
        for(;j<numsSize;j++)
        {
            if(cha==nums[j])
            {
                *p=i;
                *(p+1)=j;
                return p;
            }
        }
    }
    return NULL;
}
