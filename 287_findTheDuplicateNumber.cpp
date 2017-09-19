/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

/*
�������������ƣ����������ǲ�����ģ�����ܽ�������ͨ�����ǲ����ѡ��
˼·��
    �����鿴�����������е�ֵ����nextָ��ָ���λ�ã������д����ظ������ݣ�˵��������ڻ�·
	���ڴ��ڻ�������Ѱ�һ���ʼ�Ľڵ㣬ʹ�ÿ���ָ�뼴�ɡ�
	�����ʼλ�õ�����ʼ�ڵ�O�ľ���Ϊx������ָ������ʱB����OΪy(O->B),B->OΪd,��2(x+y)=n(y+d)+x+y
	x=(n-1)(d+y)+d; d+yΪ��һȦ�ľ��룬������ָ������ʱ����ʹ��һ��ָ���ͷ��ʼ�ߣ�����ָ��ͬʱ��
	��������Ϊ����ʼ�Ľڵ㣬����������ظ����ݡ�
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		if(nums.size()==1) return 0;
	    int slow=nums[0],fast=nums[nums[0]];
		while(slow!=fast)//����ָ��Ľ���� 
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