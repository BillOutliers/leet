/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
思路：
    乘数与被乘数都从低位开始，一位一位的进行相乘，注意进位
    时间复杂度：O(n^2)
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size()+num2.size(),'0');
		for(int i=num1.size()-1;i>=0;i--)
		{
			int carr=0;
			for(int j=num2.size()-1;j>=0;j--)
			{
				int tmp=sum[i+j+1]-'0' + (num1[i]-'0')*(num2[j]-'0')+carr;
				sum[i+j+1]=tmp%10+'0';
				carr=tmp/10;
			}
			sum[i]+=carr;
		}
		size_t startPos=sum.find_first_not_of("0");
		if(string::npos != startPos)
			return sum.substr(startPos);
		return "0";
    }
	
};

int main()
{
	char c='1';
	int t=2;
	cout<<c<<endl;
	c=t+'0';//一个整数加上一个字符,字符转化为ASIC码与整数相加，相加的结果转化为字符
	cout<<c<<endl;
	Solution mys;
	string s1="11";
	string s2="11";
	cout<<mys.multiply(s1,s2)<<endl;
	return 0;
}






















