
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

1.如果O(m+n)的空间复杂度，只需两个状态数组（长度分别为m、n）分别存储行列的状态即可，
然后根据状态数组处理矩阵即可。
2.如何用O(1)的空间复杂度来处理，还需要记录行列的状态。看到有人采用矩阵本身的一行、一列
  来作为状态数组，节约了空间。
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ;
		int row=matrix.size(),column=matrix[0].size();
		//以第一行与第一列作为状态数组
		bool row_first=false,column_first=false;
		for(int i=0;i<column;i++)//第一行状态
			if(matrix[0][i]==0)
			{
				row_first=true;
				break;
			}
		for(int i=0;i<row;i++)//第一列状态
			if(matrix[i][0]==0)
			{
				column_first=true;
				break;
			}
		for(int i=1;i<row;i++)//状态数组
			for(int j=1;j<column;j++)
				if(matrix[i][j]==0)
					matrix[0][j]=0,matrix[i][0]=0;
	    for(int i=1;i<row;i++)//按行处理
			for(int j=1;matrix[i][0]==0 && j<column;j++)
				matrix[i][j]=0;
		for(int j=1;j<column;j++)//按列处理
			for(int i=1;matrix[0][j]==0 && i<row;i++)
				matrix[i][j]=0;
		if(row_first)
			for(int i=0;i<column;i++)
				matrix[0][i]=0;
		if(column_first)
			for(int i=0;i<row;i++)
				matrix[i][0]=0;
    }
};


