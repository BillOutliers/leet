
/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

每次计算出的和值使用hash表存储，通过查看hash表判断是否有环
*/

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if(n==0) return false;
		unordered_map<int,int> m;
		while(n!=1)
		{
			if(m[n]++ == 1) return false;
			int res=n;
			n=0;
			while(res)
			{
				n+=(res%10)*(res%10);
				res/=10;
			}	
		}
		return true;
    }
};
int main()
{
	Solution mys;
	int n=34;
	cout<<mys.isHappy(n)<<endl;
	return 0;
}


