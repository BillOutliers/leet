
/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

���������ҵ�Ψһһ��û�����γ��ֵ�������Ҫ�����Ե�ʱ��(O(n)),û�ж���Ŀռ�����

���ܵ�hash��hash��Ҫ����Ŀռ䣻

����������
a^a=0
a^b^a=b;
������ֻ��һ��������һ�Σ������������������Σ�����Ľ�������Ǹ����γ��ֵ�����
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



