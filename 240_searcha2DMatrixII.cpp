
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

由于每一行从左到右、每一列从上到下都是升序，我们可以从矩阵的第一行最右侧开始
查找，如果matrix[row][column]==target则返回true;如果matrix[row][column]<target,
则说明这一行的所有数都小于target，则直接转到下一行；如果matrix[row][column]>target,
则说明这一列所有的数都大于target，则向左移动一列。
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
		int row=0,column=matrix[0].size()-1;
		while(row<matrix.size() && column>=0)
		{
			if(target == matrix[row][column]) return true;
			else if(target > matrix[row][column]) row++;
			else column--;
		}
		return false;
    }
};

