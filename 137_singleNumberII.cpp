

/*

Given an array of integers, every element appears three times except for one, 
which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it 
without using extra memory?

���������������������Σ�ֻ��һ��������һ�Σ��ҵ������

���ڳ�����һ��֮������е�������������Ʊ�ʾ��ÿһλ1���ֵĴ�����3����������
��������Щ1���㣬ʣ�µľ������յ�������ones��¼����ǰ����ı���Ϊֹ��������1
���֡�1�Ρ���mod 3 ֮��� 1������λ����twos��¼����ǰ����ı���Ϊֹ��������1����
��2�Ρ���mod 3 ֮��� 2������λ����ones��twos�е�ĳһλͬʱΪ1ʱ��ʾ������1����3�Σ�
��ʱ��Ҫ���㡣���ö�����ģ�������Ƽ��㡣����ones��¼�������ս����
*/



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
		for(int i=0;i<nums.size();i++)
		{
			ones=(ones^nums[i])& ~twos;
			twos=(twos^nums[i])& ~ones;
		}
		return ones;
    }
	int singleNumber(vector<int>& nums) {
		int one=0;//��Ӧ��λΪ1��ʾ�����ڸ�λ��1����1��
		int two=0;//��Ӧ��λΪ1��ʾ�����ڸ�λ��1����2��
		int three=0;//��Ӧ��λΪ1��ʾ�����ڸ�λ��1����3��
		for(int i=0;i<nums.size();i++)
		{
			two=two | one & nums[i];
			one=one^nums[i];
			three=one & two;
			one=one & ~three;//���������������λ
			two=two & ~three;
		}
		return one;
	}
};



