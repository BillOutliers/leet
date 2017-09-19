
/*
Given an array of size n, find the majority element. The majority element is the element 
that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

1.���� ����
2.hash����� ����
3.

����һ��������Ҫ��Ԫ������������n/2�����п���ʹ�ü��������ķ�����ѡ��һ��Ԫ��Ϊ��ҪԪ�أ�
�����һ��Ԫ����֮��ͬ�������һ�����������һ��������ֵΪ0ʱ����ѡ����һ��Ԫ��Ϊ��ҪԪ�أ�
�ظ��������̣������ҪԪ�ص�ֵ��ʹ����
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major=nums[0],cnt=1;
		for(int i=1;i<nums.size();i++)
		{
			if(cnt==0)
			{
					major=nums[i];
					cnt++;
			}			
			else if(major==nums[i])
				cnt++;
			else
				cnt--;
		}
		return major;
    }
};
int main()
{
	Solution mys;
	vector<int> nums={6,5,5};
	cout<<mys.majorityElement(nums)<<endl;
	return 0;
}