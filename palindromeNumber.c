
/*
Determine whether an integer is a palindrome. Do this without extra space.
�ж�һ���������Ƿ��ǻ��ģ����Ĺ������ĶԳƣ����һ���������ǻ��ļ�˵�������������
�뷴������ȵġ�
����������
    �������ǻ���
	���������Ϊ���Ҹ�λ�����Ϊ��Ҳ���ǻ���
*/

#include <stdio.h>

int isPalindrome(int x){
    if(x<0 ||(x!=0 && x%10==0))   
		return 0;
	int x_r=0,temp=x;
	while(temp)
	{
		x_r=x_r*10+temp%10;
		temp/=10;
	}
	return (x==x_r) ? 1 : 0;
}
int main(int argc,char **argv)
{
	int test=12321;
	printf("%d\n",isPalindrome(test));
	return 0;
}


