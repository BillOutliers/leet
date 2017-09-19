
/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

��������ֻ����2,3,5;��һ�������Էֽ�����ɸ�2,3,5�ĳ˻���ʽ������2,3,5�ı�����
��һ���涨Ϊ1������һ��2,3,5,6,8,9,10,12,15....
�������Ҫ����һ�������϶�����15����ӽ�15�����ҿ϶���ǰ��һЩ����2,3,5����
2*8=16 3*6=18 5*4=20 6*3=18 8*2=16 ��ӽ�15����16
������ǰ��м����������������ֻҪ�Ƚ�2,3,5��������ӽ�ֵ���ɣ������С�ľ�����һ��ֵ
ʹ������ָ�������2,3,5���ߵ������ˣ������´αȽ�

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


