
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
使用动态规划 按行搜索，保存每行中每个顶点的左边界、右边界、高度
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
		int m=matrix.size(),n=matrix[0].size();
		int maxR=0;
		vector<int> heights(n,0),lefts(n,0),rights(n,n);
		for(int i=0;i<m;i++)
		{
			int cur_left=0,cur_right=n;
			for(int j=0;j<n;j++)
			{//寻找每一行中每个点的左边界
				heights[j]= matrix[i][j]=='0' ? 0 : heights[j]+1;
				if(heights[j]>0)
					lefts[j]=max(lefts[j],cur_left);
				else
					lefts[j]=0,cur_left=j+1;
			}
			for(int j=n-1;j>=0;j--)
			{//寻找每一行中每个点的右边界
				if(heights[j]>0)
					rights[j] = min(rights[j],cur_right);
				else
					rights[j]=n,cur_right=j;
			}
			for(int j=0;j<n;j++)
				maxR = max(maxR,(rights[j]-lefts[j])*heights[j]);
		}
		return maxR;
    }
};




