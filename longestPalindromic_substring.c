
/*
*������ɢ��:
*    ��������ַ���s�ǻ��ģ���ô�����ĶԳƵ��ַ���������������չs1�������������
*    �ַ��������ĶԳƣ���ôs1Ҳ�ǻ��ģ������������ĵ㣬�ظ��������̣��ҵ������
*    �Ӵ���
*    ���ĶԳƷ�����������������ַ���ĳ����ĸ�Գƣ�ż�����ַ����м������ַ��Գ�
*    ʱ�临�Ӷȣ�O(n^2)   �ռ临�Ӷȣ�O(1)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
* s��Ŀ���ַ��� 
* start:�ַ���s�Ŀ�ʼλ��
* offset:��startλ�ÿ�ʼ��ƫ����
* sub_start:�����ַ�����s�еĿ�ʼλ��
* sub_offset:��sub_startλ�ÿ�ʼ��ƫ����
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
	for(;i<strlen(s);i++)//���ĵ����
	{
		diffusion(s,i,0,&sub_start,&sub_offset);//�����Ӵ�
		diffusion(s,i,1,&sub_start,&sub_offset);//ż���Ӵ�		
	}
	new_s = (char*)malloc((sub_offset+2)*sizeof(char));
	strncpy(new_s,s+sub_start,sub_offset+1);
	*(new_s+sub_offset+1)='\0';
	printf("sub_start:%d  sub_offset:%d\n",sub_start,sub_offset);
	printf("%s\n",s+sub_start);
	return new_s;
}
/*
*�ο���https://www.felix021.com/blog/read.php?2040
*Manacher's algorithm:
*    ���㷨�����п��ܵ�������ż�����ȵĻ����Ӵ���ת��Ϊ�������ȣ���ÿ���ַ�
*    ����ͬʱ����һ�������ַ�������abcb���#a#b#c#b#,a���#a#��Ϊ�˼��ٱ����
*    ���Ӷȣ����ַ�����ǰ��������һ�������ַ�����$��c�����ַ�ĩβ'\0����
*    ��һ������p����¼���ַ�s[i]Ϊ���ĵ�������ַ�������/�����ŵĳ���(����S[i]��
*    Ҳ���ǰѸû����ַ������ۺ�ĳ���)��
*    ���㷨�ĺ��������û��Ĵ��ĶԳ��������ټ��㣡����
*    mx:���Ĵ�����ұ߽�   id:���Ĵ������ĵ�
*    j=2*id-i �� i����id�Գƣ�����j<i������jΪ���ĵ��p[j] �Ѿ�����
*    ���ˣ�����p[j]���Լ���p[i]�ļ������� ��Ϊ[2*mx-id,mx]�ǻ��Ĵ�S����mx>i,
*    ��jΪ���ĵĻ��Ĵ�����iΪ���ĵĻ��Ĵ������ֻ�ȫ����S�У�p[i]=min(p[j],mx-i)
*    ��mx<=i,���ݻ��Ĵ��ĶԳ���,��i,jΪ���ĵĻ��Ĵ���������ͬ���ӻ��Ĵ���p[i]=1;
*/
char* longestPalindrome_manacher(char *s)
{
	int s_len=strlen(s);
	char *s_appen=(char *)malloc((s_len<<1 + 2)*sizeof(char));
	char *s_appen_end=s_appen;
	char *s_end=s;
	*s_appen_end++='$';
	while(*s_end != '\0')//��ԭ���鴦��Ϊ $#a#b#c# ��ʽ
	{
	    *s_appen_end++ = '#';
    	*s_appen_end++ = *s_end++;
	}
	*s_appen_end++ = '#';
	*s_appen_end = '\0';
	printf("s_append_end:%s\n",s_appen);
	//�����ַ���
	int p[(s_len<<1)+2];
	memset(p,0,sizeof(p));
	int mx=0;//���Ĵ�����ұ߽�
	int max_span=0;//����Ĵ��ĳ���
	int id=0;//���Ĵ������ĵ�
	int max_id=0;//����Ĵ������ĵ�
	int i=1,j=0;
	for(;s_appen[i]!='\0';i++)//��������p��ֵ
	{
	//	j = p[(id<<1)-i] > (mx-i) ? mx-i : p[(id<<1)-i];//С������Խ��
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
	int s_pos= (max_id-max_span)>>1;//���ַ���s�л��Ŀ�ʼ��λ��
	int s_offset= ((max_span*2-1)>>1);//���ַ���s�л��ĳ���
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






















