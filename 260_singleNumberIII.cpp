
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the 
other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

ͨ�������������鲢������������������֮��� XOR������ XOR �����Կ��Եõ����յĽ��
Ϊ AXORB = A XOR B��
ͨ��ĳ���ض��ķ�ʽ�����ǿ���ͨ�� AXORB �õ������� A ������ B �Ķ�������ĳһλ����
ͬ��λ����ΪA �� B �ǲ���ͬ�ģ��������ǵĶ�������������������һλ�ǲ���ͬ�ġ�
���ǽ���һλ����Ϊ 1���������е�����λ����Ϊ 0�����Ǽ������ǵõ����������Ϊ bitFlag��
��ô���ڣ����Ǻ�����֪�������� A �� ���� B �б�Ȼ��һ���������� bitFlag Ϊ 0��
��ΪbitFlag ��־������ A ������ B �е�ĳһλ��ͬ����ô������ A �� B �е���һλ
��Ȼ��һ��Ϊ 0����һ��Ϊ 1���������� bitFlag �н�����λ������Ϊ 0����ô��λΪ 0 
���������� bitFlag �͵��� 0������λΪ 1 ���������� bitFlag �͵��� bitFlag
��������ͼ��ˣ�����ֻ��Ҫ��ѭ��һ�����飬������ bitFlag Ϊ 0 �����ֽ��� XOR 
���㣬���� bitFlag ��Ϊ 0 ��������ж����� XOR ���㡣��ô������ǵõ������������־��� A �� B��
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		int ab=nums[0];
		for(int i=1;i<nums.size();i++)
			ab^=nums[i];
		int bitFlag=ab & (~(ab-1));//Ҫ�ҵ� A �� B �в���ͬ��λ��ֻ��Ҫ�ҵ��� AXORB �д��������һ��Ϊ 1 ��λ��������λ��������λ��Ϊ 0 ����
		vector<int> res(2,0);
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]&bitFlag)
				res[0]^=nums[i];
			else
				res[1]^=nums[i];
		}
		return res;
    }
};

