/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Ѱ���Ӵ������ص�һ�γ��ֵ�λ�ã�����KMP�㷨�������
KMP�㷨�ĺ������޻��ݣ�����next���ּ�¼�Ӵ�ÿ��ʧ���Ӧ�ô��Ӵ��ĺδ�����ƥ�䣬
�ص�����next�������⡣
*/
#include <stdio.h>
#include <string.h>
void get_next(char *t,int *next)
{
	int i=0,j=-1;
	next[0]=-1;
	while(t[i]!='\0')
	{
		if(j==-1 || t[i]==t[j])
		{
			i++,j++;
			if(t[i]!=t[j])
				next[i]=j;
			else
				next[i]=next[j];
		}
		else
			j=next[j];
	}
}
int KMP(char *s,char *t,int *next)
{
	if(s==NULL || t==NULL)
		return -1;
	int i=0,j=0;
	int len=strlen(t);
	if(len==0) return 0;//�մ� ""
	while(s[i]!='\0')
	{
		if(j==-1 || s[i]==t[j])
			i++,j++;
		else
			j=next[j];
		if(j==len)
			return i-len; 
	}
	return -1;
}


int strStr(char* haystack, char* needle)
{
	int needle_len=strlen(needle);
	printf("len:%d\n",needle_len);
	int next[needle_len+1];
	get_next(needle,next);
	return KMP(haystack,needle,next);
    
}
int main(int argc,char **argv)
{
	char s[128]="";
	char t[64]="";
	printf("%d\n",strStr(s,t));
	return 0;
}


