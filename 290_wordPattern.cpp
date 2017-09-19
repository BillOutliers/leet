
/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
ʹ������hash�����Ϊ��Ӧ���ַ���word����ֵ�洢��ͬ�����֣�����ͬ���ַ��ڴ˳���ʱ������Ӧλ��
�ϵ�word�ļ�ֵ��������ַ��ļ�ֵ��ͬ�����ʽһ���������ʽ��ͬ��

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> tmp;
		int i=0;
		for(int j=0;i<str.size() && j<=str.size();j++)//split str 
			if(str[j]==' ' || j==str.size())
			{
				tmp.push_back(str.substr(i,j-i));
				i=j+1;
			}			
		if(pattern.size()!=tmp.size()) return false;
		unordered_map<char,int> mp;
		unordered_map<string,int> ms;
		i=0;
		for(;i<pattern.size();i++)
		{
			if(i!=0 && mp[pattern[i]]!=ms[tmp[i]])
				return false;
			mp[pattern[i]]=i+1;
			ms[tmp[i]]=i+1;
		}
		return mp[pattern[i-1]]==ms[tmp[i-1]];
    }
};
int main()
{
	Solution mys;
	string pattern="aab";
	string str="dog dog dog";
	cout<<mys.wordPattern(pattern,str)<<endl;
	return 0;
}


