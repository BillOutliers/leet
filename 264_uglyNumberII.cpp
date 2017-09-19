
/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

素数因子只包括2,3,5;即一个数可以分解成若干个2,3,5的乘积形式，都是2,3,5的倍数。
第一个规定为1，则下一个2,3,5,6,8,9,10,12,15....
我们如果要求下一个数，肯定大于15且最接近15，并且肯定是前面一些数的2,3,5倍，
2*8=16 3*6=18 5*4=20 6*3=18 8*2=16 最接近15的是16
如果我们把中间过程量都存下来，只要比较2,3,5倍数的最接近值即可，求出最小的就是下一个值
使用三个指针来标记2,3,5倍走到哪里了，便于下次比较

*/



class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<1) return -1;
		vector<int> dp(n);
		dp[0]=1;
		int t2=0,t3=0,t5=0;
		for(int i=1;i<n;i++)
		{
			dp[i]=min(dp[t2]*2,min(dp[t3]*3,dp[t5]*5));
			if(dp[i]==dp[t2]*2) t2++;
			if(dp[i]==dp[t3]*3) t3++;
			if(dp[i]==dp[t5]*5) t5++;
		}
		return dp[n-1];
    }
};


