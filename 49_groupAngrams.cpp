/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
˼·��
     ʹ��hash�����洢��Щ�ַ�����ÿ��string��������õ�һ����ֵ��ӵ��
	 ��ͬ�ַ���ɵ��ַ���ӵ����ͬ�ļ�ֵ������Щ�ַ������뵽ͬһ����ֵָ���
	 �����У�Ȼ�����hash���������Ҫ���ص���Ϣ��ʽ��
iterator������������������������������ָ�������е�ĳ��Ԫ�أ�
�����Ҫ���ʸ�Ԫ�أ���Ҫ�����������ʵ�������ָ���Ԫ�أ����磺
   vector<int> v={1,2,3};
   vector<int>::iterator it=v.begin();//itָ��v�еĵ�һ��Ԫ��
   cout<<*it;//ͨ����*�������õ���������v�е�Ԫ��
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        for(int i=0;i<strs.size();i++) {
            string t = strs[i]; 
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }
        vector<vector<string>> anagrams;
        for(unordered_map<string, vector<string>>::iterator m=mp.begin();m!=mp.end();m++) { 
            vector<string> anagram(m->second.begin(), m->second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
int main()
{
    Solution mys;
	vector<std::vector<string>> res;
	vector<string> strs={"abc","add","bca"};
	res=mys.groupAnagrams(strs);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<"  ";
	    cout<<endl;
	}
	// unordered_map<string, vector<string>> mp;
	// mp["h"].push_back("hello");
	// mp["h"].push_back("hello");
	// mp["g"].push_back("gg");
	// for(unordered_map<string, vector<string>>::iterator m=mp.begin();m!=mp.end();m++)
	 // for(vector<string>::iterator it=m->second.begin();it!=m->second.end();it++)
		// cout<<*it<<endl;
	// int b=90;
	// auto aa=b;
	// cout<<aa<<endl;
//	cout<<mp["h"]<<endl;
		
    return 0;	
}
