
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
由字符串中所有字符可以构建的最长回文

不大于所有字符长度(个数>1)的偶数之和再加1.
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

