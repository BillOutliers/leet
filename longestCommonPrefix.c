

/*
Write a function to find the longest common prefix string amongst an array of strings.

���д���һֱ��ʾ runtime error ����������ͼ[]ʱ����
�տ�ʼ��ΪstrsΪ�գ��ж�ΪNULL�ͷ���NULL��������ͬ�Ĵ���
�鿴���˵Ĵ��룬���ֺ����˿��ַ��������"",���ַ����Ƿ���洢�ռ�ģ���NULL�ǲ�����
�洢�ռ�ģ�


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize)
{
	if(strsSize==0) return strs;//return "";Ҳ���ԣ��������Ǿֲ��������洢�ھ�̬��
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
















