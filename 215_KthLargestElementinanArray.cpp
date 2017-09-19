

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
在无序数组中寻找第K大的元素

使用快速查找的方法
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
		return helper(nums,0,nums.size()-1,k-1);
    }
	int helper(vector<int>&nums,int left,int right,int k)
	{
		int part=nums[left],l=left,r=right;
		while(l<r)
		{
			while(l<r && nums[r]<=part) r--;
			if(l<r) nums[l++]=nums[r];
			while(l<r && nums[l]>part) l++;
			if(l<r) nums[r]=nums[l];
		}
		nums[l]=part;
		if(l==k)
			return nums[l];
		else if(l>k)
			return helper(nums,left,l-1,k);
		else
			return helper(nums,l+1,right,k);
	}
};
int main()
{
	Solution mys;
	vector<int>nums={1,2,3,8,4,5};
	cout<<mys.findKthLargest(nums,1)<<endl;
	return 0;
}







