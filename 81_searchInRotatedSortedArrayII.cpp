
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

采用二分法的做法，跳过或者进入局部升区间；
非局部升区间时，不能直接直接跳过局部区间，注意元素的重复情况。
*/



class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
		if(n==0) return false;
		int left=0,right=n-1,mid;
		while(left<=right)
		{
			mid=(left+right)>>1;
			if(nums[mid]==target) return true;
			if(nums[mid]>nums[right])
			{
				if(target>=nums[left] && target<nums[mid])//局部升区间
				    right=mid-1;
				else
					left=mid+1;
			}
			else if(nums[mid]<nums[right])
			{
				if(target>nums[mid] && target<=nums[right])//局部升区间
					left=mid+1;
				else
					right=mid-1;
			}
			else
				right--;
		}
		return false;
    }
};


