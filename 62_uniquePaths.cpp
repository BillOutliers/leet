
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {//超时！！！！！
        if(m==1 && n==1)
			return 1;
		if(m<1 || n<1)
			return 0;
		int paths=0;
		paths+=uniquePaths(m-1,n);
		paths+=uniquePaths(m,n-1);
		return paths;
    }
	int uniquePaths2(int m, int n) {//动态规划
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
};

int main()
{
	Solution mys;
	cout<<mys.uniquePaths(1,5)<<endl;
	cout<<mys.uniquePaths2(1,5)<<endl;
	return 0;
}


