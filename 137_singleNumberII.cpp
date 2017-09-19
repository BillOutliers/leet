

/*

Given an array of integers, every element appears three times except for one, 
which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it 
without using extra memory?

数组中所有数都出现三次，只有一个数出现一次，找到这个数

对于除出现一次之外的所有的整数，其二进制表示中每一位1出现的次数是3的整数倍，
将所有这些1清零，剩下的就是最终的数。用ones记录到当前计算的变量为止，二进制1
出现“1次”（mod 3 之后的 1）的数位。用twos记录到当前计算的变量为止，二进制1出现
“2次”（mod 3 之后的 2）的数位。当ones和twos中的某一位同时为1时表示二进制1出现3次，
此时需要清零。即用二进制模拟三进制计算。最终ones记录的是最终结果。
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
		int one=0;//相应的位为1表示出现在该位上1出现1次
		int two=0;//相应的位为1表示出现在该位上1出现2次
		int three=0;//相应的位为1表示出现在该位上1出现3次
		for(int i=0;i<nums.size();i++)
		{
			two=two | one & nums[i];
			one=one^nums[i];
			three=one & two;
			one=one & ~three;//出现三次则清除该位
			two=two & ~three;
		}
		return one;
	}
};



