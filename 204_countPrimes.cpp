/*

Description:

Count the number of prime numbers less than a non-negative number, n.
*/
/*
一个素数是一个自然数恰好具有两个不同的自然数的约数：1和它本身。

通过Eratosthenes方法查找小于或等于给定整数n的所有素数：

	1.创建从2到n：（2,3,4，...，n）的连续整数的列表。
	2.最初，让p等于2，最小素数。
	3.列举的倍数p通过计数到?从2 p中的增量p，并在列表标记它们
	 （这些将是2 p，3 p，4 p，... ;所述p本身不应被标记）。
	4.找到未标记的列表中大于p的第一个数字。如果没有这样的数字，停下来。
	  否则，让p现在等于这个新数字（这是下一个素数），并从第3步重复。
	5.当算法终止时，列表中没有标记的数字都是n以下的素数。
这里的主要思想是，给予p的每个值都将是主要的，因为如果它是复合的，它将被标记
为其他一些较小的素数的倍数。请注意，其中一些数字可能会被标记不止一次（例如，15号将被标记为3和5）。

作为改进，它足以标记在步骤3中的数字与起始p 2，作为对所有较小的倍数p将已经被标记在该点。
这意味着当p 2大于n时，允许算法在步骤4中终止。[1]

另一个改进是最初列出奇数只，（3，5，......，?），并且在递增计数2 p从p 2在步骤3中，
从而仅标记的奇数倍p。这实际上出现在原始算法中。[1]这可以通过车轮因子分解来概括，仅从数字
与初始几个素数互补形成初始列表，而不仅仅是从赔率（即，数字与2互换），并以相应调整的增量计数，
以便只有这样的倍数的p是生成与这些小素数互补的，首先。[6]
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
		if(n<=2) return 0;
		vector<bool> tmp(n,false);
		int i=3,res=1;
		int upbound=sqrt(n);
		for(;i<n;i+=2)
		{
			if(!tmp[i])
			{
				res++;
				if(i>upbound) continue;
				for(int j=i*i;j<n;j+=i)
					tmp[j]=true;
			}
		}
		return res;
    }
};
int main()
{
	Solution mys;
	int n=2;
	cout<<mys.countPrimes(n)<<endl;
	return 0;
}



