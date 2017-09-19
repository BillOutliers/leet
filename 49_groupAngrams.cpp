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
思路：
     使用hash表来存储这些字符串，每个string进行排序得到一个键值，拥有
	 相同字符组成的字符串拥有相同的键值，把这些字符串存入到同一个键值指向的
	 容器中；然后遍历hash表来组成需要返回的信息格式。
iterator迭代器，可用于容器遍历；迭代器指向容器中的某个元素，
如果需要访问该元素，需要解引用来访问迭代器所指向的元素，例如：
   vector<int> v={1,2,3};
   vector<int>::iterator it=v.begin();//it指向v中的第一个元素
   cout<<*it;//通过“*”解引用迭代器访问v中的元素
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
