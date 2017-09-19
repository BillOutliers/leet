/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
两个指针问题
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
		while(left<right)
		{
			while(left<right && isalnum(s[left]) == false)
				left++;
			while(left<right && isalnum(s[right]) == false )
				right--;
			if(left>=right) return true;
			if(toupper(s[left]) != toupper(s[right]))
				return false;
			left++,right--;
		}
		return true;
    }
};
int main()
{
	Solution mys;
	string s="canal: Panama";
	cout<<mys.isPalindrome(s)<<endl;
	return 0;
}


