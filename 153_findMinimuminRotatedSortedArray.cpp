/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid=0;
		if(nums[left]<nums[right]) return nums[left];//Ã»ÓÐÐý×ª
		while(left<right)
		{
			mid=(left+right)>>1;
			if(nums[mid] >nums[left] && nums[mid]>nums[right])
			    left=mid+1;
			else if(nums[mid] <nums[left] && nums[mid]<nums[right])
				right=mid;
			else if(nums[left]>=nums[right])
				left++;
			else
				right--;
		}
		return nums[left];
    }
};
int main()
{
	Solution mys;
	vector<int> nums={2,3,4,5,1};
	cout<<mys.findMin(nums)<<endl;
	return 0;
}