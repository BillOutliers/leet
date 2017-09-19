
/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
���ַ����������ַ����Թ����������

�����������ַ�����(����>1)��ż��֮���ټ�1.
*/


class Solution {
public:
    int longestPalindrome(string s) {
		if(s.size()==0) return 0;
        unordered_map<char,int> mp;
		int res=0;
		for(int i=0;i<s.size();i++)
		{
			if(mp[s[i]]++ == 1)
			{
				res+=2;
				mp[s[i]]=0;
			}
		}
		return res < s.size() ? res+1 : res;
    }
};

