/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

˼·��
    ��ÿ�����ַ�����ȷ��λ���ϣ�������С�����鳤��lenʱ��
	����Ͱ��������3����nums[2]��λ�á�
	��С��0�����len��Ԫ�ز����д���
	���������a[i]!=i+1ʱ�����ֵ�һ����ʧ��������,����i+1
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
		for(int i=0;i<len;i++)
			while(nums[i]>0 && nums[i]<=len && nums[nums[i]-1]!=nums[i])
				swap(nums[i],nums[nums[i]-1]);
		for(int j=0;j<len;j++)
			if(nums[j]!=j+1)
				return j+1;
		return len+1;
    }
};
int main()
{
    Solution mys;
	vector<int> candidates;//={2,3,7};[10, 1, 2, 7, 6, 1, 5]
	candidates.push_back(1);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	int res=mys.firstMissingPositive(candidates);
	cout<<res<<endl;
		
    return 0;	
}



