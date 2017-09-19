
/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

思路1：桶排序
       由于只有三个数0、1、2，可以利用桶排序对相应的值出现的次数进行计数，
	   然后根据计数值对原始数据重新赋值即可。
思路2：类似快速排序，从两边开始比较进行挖坑交换排序。
      
	   
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> storeNum(3,0);
		int i;
		for(i=0;i<nums.size();i++)
			storeNum[nums[i]]++;
		for(i=0;i<storeNum[0];i++)
			nums[i]=0;
		for(;i<storeNum[0]+storeNum[1];i++)
			nums[i]=1;
		for(;i<nums.size();i++)
			nums[i]=2;
    }
	void sortColors2(vector<int>& nums) {
	     int red=0,blue=nums.size()-1;
		 for(int i=0;i<=blue;)
		 {
			 if(nums[i]==0)
				 swap(nums[i++],nums[red++]);
			 else if(nums[i]==2)
				 swap(nums[i],nums[blue--]);
			 else
				 i++;
		 }
	}
};



