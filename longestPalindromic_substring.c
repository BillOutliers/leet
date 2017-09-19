
/*
*中心扩散法:
*    如果中心字符串s是回文，那么以中心对称的字符串向左右两边扩展s1，如果左右两边
*    字符关于中心对称，那么s1也是回文，遍历所有中心点，重复上述过程，找到最长回文
*    子串。
*    中心对称分两种情况，奇数个字符以某个字母对称；偶数个字符以中间两个字符对称
*    时间复杂度：O(n^2)   空间复杂度：O(1)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
* s：目的字符串 
* start:字符串s的开始位置
* offset:以start位置开始的偏移量
* sub_start:回文字符串在s中的开始位置
* sub_offset:以sub_start位置开始的偏移量
*/
void diffusion(char *s,int start,int offset,int *sub_start,int *sub_offset)
{
	char *left=s+start;
	char *right=s+start+offset;
	int len=strlen(s);
	char *end=s+len;
	while(left>=s && right<end && (*left == *right))
	{
		left--;
		right++;
	}
	if(*sub_offset <= (right-left-2))
	{
		*sub_offset = (right-left-2)/sizeof(char);
		*sub_start = (left+1-s)/sizeof(char);
	}
}
char* longestPalindrome(char* s) {
    int i=0;
	int sub_start=0;
	int sub_offset=0;
	char *new_s=NULL;
	for(;i<strlen(s);i++)//中心点遍历
	{
		diffusion(s,i,0,&sub_start,&sub_offset);//奇数子串
		diffusion(s,i,1,&sub_start,&sub_offset);//偶数子串		
	}
	new_s = (char*)malloc((sub_offset+2)*sizeof(char));
	strncpy(new_s,s+sub_start,sub_offset+1);
	*(new_s+sub_offset+1)='\0';
	printf("sub_start:%d  sub_offset:%d\n",sub_start,sub_offset);
	printf("%s\n",s+sub_start);
	return new_s;
}
/*
*参考：https://www.felix021.com/blog/read.php?2040
*Manacher's algorithm:
*    该算法将所有可能的奇数、偶数长度的回文子串都转换为奇数长度，即每个字符
*    两边同时插入一个特殊字符。比如abcb变成#a#b#c#b#,a变成#a#；为了减少编码的
*    复杂度，在字符串最前面增加另一个特殊字符，如$。c语言字符末尾'\0‘。
*    用一个数组p来记录以字符s[i]为中心的最长回文字符串向左/右扩张的长度(包括S[i]，
*    也就是把该回文字符串对折后的长度)。
*    该算法的核心是利用回文串的对称性来减少计算！！！
*    mx:回文串最大右边界   id:回文串的中心点
*    j=2*id-i 与 i关于id对称，假设j<i，则以j为中心点的p[j] 已经计算
*    过了，利用p[j]可以减少p[i]的计算量。 因为[2*mx-id,mx]是回文串S，若mx>i,
*    以j为中心的回文串与以i为中心的回文串都部分或全部在S中，p[i]=min(p[j],mx-i)
*    若mx<=i,根据回文串的对称性,以i,j为中心的回文串不在有相同的子回文串，p[i]=1;
*/
char* longestPalindrome_manacher(char *s)
{
	int s_len=strlen(s);
	char *s_appen=(char *)malloc((s_len<<1 + 2)*sizeof(char));
	char *s_appen_end=s_appen;
	char *s_end=s;
	*s_appen_end++='$';
	while(*s_end != '\0')//把原数组处理为 $#a#b#c# 格式
	{
	    *s_appen_end++ = '#';
    	*s_appen_end++ = *s_end++;
	}
	*s_appen_end++ = '#';
	*s_appen_end = '\0';
	printf("s_append_end:%s\n",s_appen);
	//处理字符串
	int p[(s_len<<1)+2];
	memset(p,0,sizeof(p));
	int mx=0;//回文串最大右边界
	int max_span=0;//最长回文串的长度
	int id=0;//回文串的中心点
	int max_id=0;//最长回文串的中心点
	int i=1,j=0;
	for(;s_appen[i]!='\0';i++)//计算数组p的值
	{
	//	j = p[(id<<1)-i] > (mx-i) ? mx-i : p[(id<<1)-i];//小心数组越界
		p[i] = mx > i ? (p[(id<<1)-i] > (mx-i) ? mx-i : p[(id<<1)-i]) : 1;
		while(s_appen[i+p[i]] == s_appen[i-p[i]]) p[i]++;
		if(i+p[i] > mx)
		{
			mx=i+p[i];
			id=i;
		}
		if(p[i]>max_span)
		{
			max_span=p[i];
			max_id=i;
		}
		printf("%d  ",p[i]);
	}
	int s_pos= (max_id-max_span)>>1;//在字符串s中回文开始的位置
	int s_offset= ((max_span*2-1)>>1);//在字符串s中回文长度
	printf("\n max_span:%d max_id:%d \n",max_span,max_id);
	char *s_new=(char *)malloc((s_offset+1)*sizeof(char));
	strncpy(s_new,s+s_pos,s_offset);
	*(s_new+s_offset)='\0';
	free(s_appen);
	return s_new;
}


int main(int argc,char **argv)
{
	char *s="cbbd";
	printf("%s\n",longestPalindrome_manacher(s));
	printf("%s\n",longestPalindrome(s));
	return 0;
}






















