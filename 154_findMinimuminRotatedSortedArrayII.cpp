#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid=0;
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
	vector<int> nums={2,2,2,1,1,1,2};
	cout<<mys.findMin(nums)<<endl;
	return 0;
}