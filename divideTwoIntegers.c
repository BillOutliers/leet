
/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
思路：
    通过移位运算来计算倍数 右移n位是2^n倍
溢出条件：
    1.divisor =0; 除数为0
	2.dividend=INT_MIN && divisor=-1 (因为abs(INT_MIN)=INT_MAX+1 溢出)
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