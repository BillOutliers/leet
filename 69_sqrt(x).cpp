/*

Implement int sqrt(int x).

Compute and return the square root of x.


*/
/*
˼·1��ʹ�ö��ַ��ƽ����
       x�ĸ�������x/2+1,ֻ����[0,X/2+1]�ڶ��ֲ��Ҽ���
	   ֤���� sqrt(x)<=x/2+1 => x<= (x/2+1)^2 => x<=x^2/4+1+x => x^2/4+1 =>0�������
˼·2��ʹ��ţ�ٵ���
       x^2=r => f(x)=x^2-r ��f(x)=0ʱ�Ľ⣬��(Xi,Xi^2-r)Ϊf(x)�ϵ�һ�㣬���õ������
	   ����Ϊ f(x)-f(Xi)=f'(Xi)*(x-Xi),�����߷��̵���0���������x=x-f(Xi)/f'(Xi)
	   => x=x-(Xi^2-r)/(2*Xi)=(Xi+r/Xi)/2
	   ͨ��ÿ���ж�ǰ�����ε������Ľ���Ƿ��������������

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