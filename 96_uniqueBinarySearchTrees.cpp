
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
卡特兰数：
h(0)=1,h(1)=1
递推公式 
         h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n>=2)
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> ca(n+1,0);
		ca[0]=1,ca[1]=1;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=i;j++)
				ca[i]+=ca[j-1]*ca[i-j];
		return ca[n];
    }
};


