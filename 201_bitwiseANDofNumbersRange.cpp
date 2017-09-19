
/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.


last bit of (odd number & even number) is 0.
when m != n, There is at least an odd number and an even number, so the last bit position result is 0.
Move m and n rigth a position.
找到m,n左边公共的部分即可
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
		while(m != n)
		{
			m>>=1;
			n>>=1;
			i++;
		}
		return m<<i;
    }
};


