/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

/*
由于条件的限制，进行排序是不允许的！如果能进行排序，通排序将是不错的选择。
思路：
    把数组看成链表，数组中的值看成next指针指向的位置，数组中存在重复的数据，说明链表存在环路
	对于存在环的链表，寻找环开始的节点，使用快慢指针即可。
	如果起始位置到环开始节点O的距离为x，快慢指针相遇时B点离O为y(O->B),B->O为d,则2(x+y)=n(y+d)+x+y
	x=(n-1)(d+y)+d; d+y为环一圈的距离，当快慢指针相遇时，再使用一个指针从头开始走，与满指针同时走
	相遇出即为环开始的节点，我们所求的重复数据。
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		if(nums.size()==1) return 0;
	    int slow=nums[0],fast=nums[nums[0]];
		while(slow!=fast)//快慢指针的交汇点 
		{
			slow=nums[slow];
			fast=nums[nums[fast]];
		}
		slow=0;
		while(slow != fast)//
		{
			slow=nums[slow];
			fast=nums[fast];
		}
		return fast;
    }
};