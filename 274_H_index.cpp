/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N ? h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

首先进行降序排序
寻找第一个第i个数小于i的位置，前一个位置的索引i即为H值。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   static bool compares(int a,int b)
	{
		return a>b;
	}
    int hIndex(vector<int>& citations) {
		if(citations.empty()) return 0;
        sort(citations.begin(),citations.end(),Solution::compares);
		for(int j=0;j<citations.size();j++)
			cout<<citations[j]<<endl;
		int i=0;
		for(;i<citations.size();i++)
		{
			if(citations[i]<i+1)
				return i;
		}
		return i;
    }
};
int main()
{
	Solution mys;
	vector<int> citations={3,0,6,1,5};
	cout<<mys.hIndex(citations)<<endl;
	return 0;
}


