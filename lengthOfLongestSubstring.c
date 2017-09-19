

#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{
	int len=0;
	char *end=s,*temp;
	char *addrsTabble[128]={NULL};
	while(*end !='\0')
	{
		temp=addrsTabble[*end];
		addrsTabble[*end]=end;
		if(temp>=s){
			len= end-s >len ? end-s:len;
			s=temp+1;
		}end++;	
	}
	len= end-s >len ? end-s:len;
	return len;
}

int main(int argc,char **argv)
{
	int len=0;
	char *s=*++argv;
	printf("%s\n",s);
	
	len=lengthOfLongestSubstring(s);
	printf("%d\n",len);
	printf("%s\n",s+len);
	return 0;
}
/*
*获取字符串最长子串，为了避免回溯，采用一个数组指针，每个字符
*对应的值作为数组索引并指向该字符开始的子串；在遍历该字符串的
*过程中，数组指针指向该字符最后一次出现的位置；
*temp指向 字符*end 上一次在字符串中出现的位置，然后让addr[*end]
*指向字符*end当前位置；若temp指针指向的位置在s指针的右边，则根据
*temp指针指向的位置调整s指针的位置。
*
*/

int len_subStr(char *s)
{
	int length=0;
	char *end=s,*temp;
	char *addr[128]={NULL};
	while(*end !='\0')
	{
		temp=addr[*end];
		addr[*end]=end;
		if(temp >= s){
			length = end-s>length ? end-s : length;
			s=temp+1;
		}end++;
	}
	length = end-s>length ? end-s : length;
	return length;
}










