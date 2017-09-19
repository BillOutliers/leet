/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/


class Solution {
public:
    int lengthOfLastWord(string s) {
       int res=0,tail=s.size()-1;
	   while(tail>=0 && s[tail]==' ') tail--;//寻找最后一个非空字符
	   while(tail>=0 && s[tail--]!=' ')//寻找上一个空字符
		   res++;
	   return res;
	
    }
};


