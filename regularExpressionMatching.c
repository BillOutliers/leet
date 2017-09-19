

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true

*
The asterisk indicates zero or more occurrences of the preceding element.
For example, ab*c matches "ac", "abc", "abbc", "abbbc", and so on.
 “*”代表之前的那个字符可以是0个或者任意多个
*/
#include <stdio.h>
#include <string.h>


/*
采用递归解决：
    若p为空，s也为空返回true，否则返回false
	若p[1]=='*'时，’*‘代表0个前面的字符时，把p的前两个丢掉进行递归；’*‘代表多个前一个字符
	时，若果s字符长度大于1，则比较完s[0]==p[0]后，把s的第一个字符丢掉然后进行递归。
	若p[1]!='*'时，且s_len不为零，则把s p的第一个字符都丢掉并递归。
*/
int isMatch(char* s, char* p){
    int s_len=strlen(s);
	int p_len=strlen(p);
	if(p_len==0) return s_len==0;
	if(p_len>1 && p[1]=='*')
	    return isMatch(s,&(p[2])) || (s_len!=0 && (s[0]==p[0]||p[0]=='.') && isMatch(&(s[1]),p));
	else
		return s_len!=0 && (s[0]==p[0] || p[0]=='.') && isMatch(&(s[1]),&(p[1]));
}
/*
参考：https://discuss.leetcode.com/topic/17852/9-lines-16ms-c-dp-solutions-with-explanations
采用动态规划：
   This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true
   if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:
	P[i][j] = P[i-1][j-1],if p[j-1] != '*' && (s[i-1] == p[j-1] || p[j-1] == '.');
	P[i][j] = P[i][j-2], if p[j-1] == '*' and the pattern repeats for 0 times;
	P[i][j] = P[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'), if p[j-1] == '*' and the pattern repeats 
	for at least 1 times. 
*/
int isMatch_dp(char *s,char *p)
{
	int s_len=strlen(s);
	int p_len=strlen(p);
	int dp[s_len+1][p_len+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;//s p 长度为0时 为真
	int i,j;
	for(i=0;i<=s_len;i++)
	    for(j=1;j<=p_len;j++)
		{
			if(j>1 && p[j-1]=='*')
				dp[i][j]=dp[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
			else
				dp[i][j]=i>0 && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
			
		}
	return dp[s_len][p_len];
}
int main(int argc,char **argv)
{
	char s[]="aa";
	char p[]=".*";
	printf("%d\n",isMatch(s,p));
	printf("%d\n",isMatch_dp(s,p));
	return 0;
}

















