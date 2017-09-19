/*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.

����һ�����ֳ��ֵĴ��������������������磺
    1.  1    1��1
	2.  11   ��һ����Ϊ1����Ϊ1��1��ǰһ��1��ʾ��������һ����ʾֵ
	3.  21    11��Ϊ2��1 ��Ϊ 21
*/


#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
         if(n==0) return "";
		 string re="1";
		 int cnt=1;		
		 while(--n)
		 {
			string tmp="";
			for(int i=0;i<re.size();i++)
			{
				cnt=1;
				stringstream buf;
				while(i+1<re.size() && (re[i]==re[i+1]))
					cnt++,i++;
				buf<<cnt;//����ת��Ϊ�ַ���
				tmp+= buf.str() +re[i];
				// cout<<"tmp:"<<tmp<<endl;
			}
			re=tmp;
		 }
		 return re;
    }
};

int main()
{
	Solution mys;//=new Solution();
	cout<<mys.countAndSay(5)<<endl;
	
	return 0;
}






