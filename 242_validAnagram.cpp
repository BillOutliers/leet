
/*

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
		unordered_map<char,int> mps;
		unordered_map<char,int> mpt;
		for(int i=0;i< s.size();i++)
		    mps[s[i]]++,mpt[t[i]]++;
		for(int i=0;i<s.size();i++)
			if(mps.find(t[i])==mps.end() || mps[t[i]]!=mpt[t[i]])
				return false;
		return true;
    }
	 bool isAnagram2(string s, string t) {
        if(s.size()!=t.size()) return false;
		unordered_map<char,int> mp;
		for(int i=0;i< s.size();i++)
		    mp[s[i]]++,mp[t[i]]--;
		for(int i=0;i<s.size();i++)
			if(mp[s[i]]!=0)
				return false;
		return true;
    }
};



