/*
Given a m x n grid filled with non-negative numbers, find a path from top left to 
bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/*
   dp[i][j] = dp[i][j-1] < dp[i-1][j] ? grid[i][j]+dp[i][j-1] : grid[i][j]+dp[i-1][j];
   如果用一个一位数组来存储中间值，需要单独处理第一行与第一列
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
		vector<int> dp(n+1,0);
		for(int i=0;i<m;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==0) dp[j]=dp[j-1]+grid[i][j-1];
				else if(j==1) dp[j]=dp[j]+grid[i][j-1];
				else 
					dp[j] = dp[j-1] < dp[j] ? dp[j-1]+grid[i][j-1] : dp[j]+grid[i][j-1];
			}
		return dp[n];
    }
};
int main()
{
	Solution mys;
	vector<vector<int> >grid={{1,2},{1,1}};
	cout<<mys.minPathSum(grid)<<endl;
	return 0;
}


