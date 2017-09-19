/*

Implement int sqrt(int x).

Compute and return the square root of x.


*/
/*
思路1：使用二分法逼近求解
       x的根不大于x/2+1,只需在[0,X/2+1]内二分查找即可
	   证明： sqrt(x)<=x/2+1 => x<= (x/2+1)^2 => x<=x^2/4+1+x => x^2/4+1 =>0恒成立。
思路2：使用牛顿迭代
       x^2=r => f(x)=x^2-r 当f(x)=0时的解，设(Xi,Xi^2-r)为f(x)上的一点，过该点的切线
	   方程为 f(x)-f(Xi)=f'(Xi)*(x-Xi),令切线方程等于0，即可求得x=x-f(Xi)/f'(Xi)
	   => x=x-(Xi^2-r)/(2*Xi)=(Xi+r/Xi)/2
	   通过每次判断前后两次迭代出的结果是否相等来结束迭代

*/
#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long long left=0;
		long long right=x/2+1;
		while(left<=right)
		{
			long long mid=(left+right)>>1;
			long long sq=mid*mid;
			if(sq==x) return mid;
			else if(sq<x)left=mid+1;
			else right=mid-1;
		}
		return right;
    }
	int mySqrt2(int x){
		long r=x/2+1;
		while(r*r > x)
		{
			r=(r+x/r)>>1;
		}
		return r;
	}
};

int main()
{
	Solution mys;
	cout<<mys.mySqrt(6)<<endl;
	return 0;
}