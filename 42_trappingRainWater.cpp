
/*
Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

˼·��
    ͨ���ۻ����ܺͣ����������߿�ʼ��������Ǳ��������е��������ߵ����ֵ��
	maxL,maxR,�����Ĺ����б�����������߶ȣ�
	����λ�ý��бȽϣ�Ȼ���ж��ǽ�����߻��ұ߲���(�����߶�С��)��
	��������߲����������ֵheight[left]��maxL���бȽ�Ȼ����и���maxL
	��ֵ��sumֵ���Ҳ�ͬ��.
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
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
		int sum=0,maxL=0,maxR=0;
		while(left<right)
		{
			if(height[left]<=height[right])
			{
				if(height[left]>=maxL) maxL=height[left];
				else sum+=maxL-height[left];
				left++;
			}
			else
			{
				if(height[right]>=maxR) maxR=height[right];
				else sum+=maxR-height[right];
				right--;
			}
		}
		return sum;
    }
};
int main()
{
    Solution mys;
	vector<int> candidates;//[0,1,0,2,1,0,1,3,2,1,2,1]
	candidates.push_back(0);
	candidates.push_back(1);
	candidates.push_back(0);
	candidates.push_back(2);
	candidates.push_back(1);
	candidates.push_back(0);
	candidates.push_back(1);
	candidates.push_back(3);
	candidates.push_back(2);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(1);
	int res=mys.trap(candidates);
	cout<<res<<endl;
		
    return 0;	
}

