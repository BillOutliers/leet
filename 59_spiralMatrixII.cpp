/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
		int row_u = 0,row_d=n-1,column_l=0,column_r=n-1;
		int k=1;
		while(k <= n*n)
		{
			for(int i=column_l;i<=column_r;i++)//上面一行
				res[row_u][i]=k++;
			row_u++;
			for(int i=row_u;i<=row_d;i++)//右边一列
				res[i][column_r]=k++;
			column_r--;
			for(int i=column_r;i>=column_l;i--)//下面一行
				res[row_d][i]=k++;
			row_d--;
			for(int i=row_d;i>=row_u;i--)//左边一列
				res[i][column_l]=k++;
			column_l++;
		}
		return res;
    }
};



