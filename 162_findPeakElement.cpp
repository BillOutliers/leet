
/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] �� num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -��.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
Ѱ��һ����ֵ
���ڼٶ�num[-1]=num[n]=-��;���������������������ǵ�����ݼ������������һ����ֵ

Ҫ��log(n)��ʱ�临�Ӷȣ�ʹ�ö��ַ�������
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1;
		while(left<right)
		{
			int mid=(left+right)>>1;
			if(nums[mid]>nums[mid+1])
				right=mid;
			else
				left=mid+1;
		}
		return left;
    }
};

