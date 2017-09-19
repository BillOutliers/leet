
/*
Given an array of size n, find the majority element. The majority element is the element 
that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

1.排序 查找
2.hash表计数 遍历
3.

由于一定存在主要的元素且数量大于n/2，所有可以使用计数抵消的方法，选第一个元素为主要元素，
如果下一个元素与之相同则计数加一，否则计数减一；当计数值为0时，在选择下一个元素为主要元素，
重复上述过程，最后主要元素的值即使所求。
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