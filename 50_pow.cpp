/*
Implement pow(x, n).
*/

#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
		if(n==0) return 1;
        double res=1;
		unsigned long long p=n;
		if(n<0)
		{
			p=-n;
			x=1/x;
		}
		while(p)
		{
			if(p&1)
				res*=x;
			x*=x;
			p>>=1;
		}
		return res;
    }
};
int main()
{
	int tmp=-2;
	int x=0;
	Solution mys;
	cout<<mys.myPow(x,tmp)<<endl;
	return 0;
}
