
/*
*��һ���ַ���ת��Ϊ����ֵ:
*    ��ʼλ�õĿո� ȥ��
*    ����λ  ����¼
*    �ַ����еķǷ��ַ���ֱ���˳���������ǰֵ
*    ת����Ľ���Ƿ�Խ�磬�������ֵ����Сֵ
*
*/

#include <stdio.h>
#include <math.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648


int myAtoi(char* str) {
    int sign=1;
	long re=0;
	while(*str == ' ') str++;// skip space
	if(*str == '-' || *str == '+')
	{
		sign = (*str== '-') ? -1 : 1;
	    str++;
	}
	while(*str>='0' && *str<='9')
	{
		re = re*10 + (*str++ - '0');
		if(re > INT_MAX) 
			return (sign==1) ? INT_MAX : INT_MIN;
	}
	return re*sign;
}
int main(int argc,char **argv)
{
	char  test[]="   -56214  7483647";
	printf("test:%s  test_reverse:%d\n",test,myAtoi(test));
	return 0;
}


