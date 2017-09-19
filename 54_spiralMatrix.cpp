
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

右螺旋输出矩阵
	先输出最上面一行，然后是最右边一列，最下面一行，最右边一列；去掉外层一圈，执行上一步。

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
		int r=matrix.size(),c = matrix[0].size();
		vector<int> res(r*c);
		int row_u = 0,row_d = r-1,columns_l = 0,columns_r = c-1,k = 0;
		while(true)
		{
			//上面一行
			for(int i = columns_l;i<= columns_r;i++) 
				res[k++] = matrix[row_u][i];
			if(++row_u > row_d) break;
			//右边一列
			for(int i = row_u;i<= row_d;i++)
				res[k++] = matrix[i][columns_r];
			if(--columns_r < columns_l) break;
			//下面一行
			for(int i = columns_r;i>= columns_l;i--)
				res[k++]= matrix[row_d][i];
			if(--row_d < row_u) break;
			//左边一列
			for(int i = row_d;i>= row_u;i--)
				res[k++] = matrix[i][columns_l];
			if(++columns_l > columns_r) break;
		}
		return res;
    }
};







