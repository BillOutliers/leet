
/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
˼·��
    ͨ����λ���������㱶�� ����nλ��2^n��
���������
    1.divisor =0; ����Ϊ0
	2.dividend=INT_MIN && divisor=-1 (��Ϊabs(INT_MIN)=INT_MAX+1 ���)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
int divide(int dividend, int divisor){
    if(divisor==0 || (dividend==MIN_INT && divisor==-1)) return MAX_INT;
	int sign= (dividend>0)^(divisor>0) ? -1 : 1;
	long dvd= labs(dividend);//dividend >=0 ? dividend : -dividend;
	long dvs= labs(divisor);//divisor >=0 ? divisor : -divisor;
	printf("dvd:%ld\n",dvd);
	int re=0,tmp,mult,i;
	while(dvd>=dvs)
	{
		i=1;
		while(dvd >=(dvs<<i))
		    i++;
		dvd-=dvs<<(i-1);
		re+=1<<(i-1);
	}
	return sign==1 ? re : -re;
}
int main()
{
	int a=234324;
	int b=3;
	printf("%d\n",divide(a,b));
	return 0;
}