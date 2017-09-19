
/*
Given an integer, write a function to determine if it is a power of two.
判断一个数是否为2的幂
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
		int cnt=0;
		for(int i=0;i<32;i++)
		{
			cnt += n&1;
			n>>=1;
		}
		return cnt==1 ? true : false;
    }
	bool isPowerOfTwo2(int n) {
		if(n<=0) return false;
		return !(n&(n-1));
	}
};


