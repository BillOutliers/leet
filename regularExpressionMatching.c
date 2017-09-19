

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
 ��*������֮ǰ���Ǹ��ַ�������0������������
*/
#include <stdio.h>
#include <string.h>


/*
���õݹ�����
    ��pΪ�գ�sҲΪ�շ���true�����򷵻�false
	��p[1]=='*'ʱ����*������0��ǰ����ַ�ʱ����p��ǰ�����������еݹ飻��*��������ǰһ���ַ�
	ʱ������s�ַ����ȴ���1����Ƚ���s[0]==p[0]�󣬰�s�ĵ�һ���ַ�����Ȼ����еݹ顣
	��p[1]!='*'ʱ����s_len��Ϊ�㣬���s p�ĵ�һ���ַ����������ݹ顣
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
�ο���https://discuss.leetcode.com/topic/17852/9-lines-16ms-c-dp-solutions-with-explanations
���ö�̬�滮��
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
	dp[0][0]=1;//s p ����Ϊ0ʱ Ϊ��
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

















