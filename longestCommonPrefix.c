

/*
Write a function to find the longest common prefix string amongst an array of strings.

运行代码一直提示 runtime error ，并且在试图[]时错误，
刚开始以为strs为空，判断为NULL就返回NULL，还是相同的错误！
查看别人的代码，发现忽视了空字符串的情况"",空字符串是分配存储空间的，而NULL是不分配
存储空间的！


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize)
{
	if(strsSize==0) return strs;//return "";也可以，常量不是局部变量，存储在静态区
    int len_one=strlen(strs[0]);
	printf("len_one:%d\n",len_one);
	char *longPre=(char*)malloc((len_one+1)*sizeof(char));
	char *re=longPre;
	int i=0,j=1;
    for(;i<len_one;i++) 
	{
		char c=strs[0][i];
		for(j=1;j<strsSize;j++)
		{
            if(strs[j][i]=='\0' || c!=strs[j][i])
			{
				*longPre='\0';
				return re;
			}				
		}
		*longPre++=c;
	}	
    *longPre='\0';	
	return re;		
}
int main()
{
	char *strs[3]={""};//,"abbcde","abbcdg"};
	if(longestCommonPrefix(strs,1)!=NULL)
		printf("%s\n",longestCommonPrefix(strs,1));
	return 0;
}
















