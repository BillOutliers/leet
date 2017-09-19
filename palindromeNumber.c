
/*
Determine whether an integer is a palindrome. Do this without extra space.
判断一个整型数是否是回文，回文关于中心对称；如果一个整形数是回文即说明这个数的正序
与反序是相等的。
特殊的情况：
    负数不是回文
	如果整数不为零且个位数如果为零也不是回文
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


