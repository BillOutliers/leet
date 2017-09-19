
/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

在数组中找到唯一一个没有两次出现的整数，要求线性的时间(O(n)),没有额外的空间消耗

不能的hash表，hash需要额外的空间；

采用异或操作
a^a=0
a^b^a=b;
数组中只有一个数出现一次，其他的数都出现两次，异或后的结果就是那个单次出现的整数
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=nums[0];
		for(int i=1;i<nums.size();i++)
			res^=nums[i];
		return res;
    }
};



