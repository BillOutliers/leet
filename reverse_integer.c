/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

*/
#include <stdio.h>
#include <math.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int reverse(int x)
{
	long res=0;
	while(x)
	{
		res=res*10+x%10;
		x/=10;
	}
	return (res>INT_MAX || res<INT_MIN) ? 0 : res;
}

int main(int argc,char **argv)
{
	int test=2147483647;
	printf("test:%d  test_reverse:%d\n",test,reverse(test));
	return 0;
}