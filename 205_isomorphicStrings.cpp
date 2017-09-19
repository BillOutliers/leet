
/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
用两个hash表分别存储两个字符串，以字符为hash表的键，如果键值不同，则不匹配
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> v_s(255,0);
        vector<char> v_t(255,0);
		for(int i=0;i<s.size();i++)
		{
			if(v_s[s[i]]!=v_t[t[i]]) return false;
			v_s[s[i]]=i+1;
			v_t[t[i]]=i+1;
		}
		return true;
    }
};


