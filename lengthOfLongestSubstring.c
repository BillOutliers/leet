

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
*��ȡ�ַ�����Ӵ���Ϊ�˱�����ݣ�����һ������ָ�룬ÿ���ַ�
*��Ӧ��ֵ��Ϊ����������ָ����ַ���ʼ���Ӵ����ڱ������ַ�����
*�����У�����ָ��ָ����ַ����һ�γ��ֵ�λ�ã�
*tempָ�� �ַ�*end ��һ�����ַ����г��ֵ�λ�ã�Ȼ����addr[*end]
*ָ���ַ�*end��ǰλ�ã���tempָ��ָ���λ����sָ����ұߣ������
*tempָ��ָ���λ�õ���sָ���λ�á�
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










