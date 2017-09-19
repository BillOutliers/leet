
/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
		int row=matrix.size(),column=matrix[0].size();
		if(matrix[0][0]>target || matrix[row-1][column-1]<target) return false;
		//寻找位于第几行
		int left=0,right=row-1;
		int mid,target_row;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(matrix[mid][0]==target)
				return true;
			else if(matrix[mid][0]<target)
				left=mid+1;
			else
				right=mid-1;
		}
		target_row=left-1;
		left=0,right=column-1;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(matrix[target_row][mid]==target)
				return true;
			else if(matrix[target_row][mid]<target)
				left=mid+1;
			else
				right=mid-1;
		}
		return false;
		//Runtime Error Message: reference binding to null pointer of type 'value_type' ?????
		//不知道什么原因??
    }
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		//把二维矩阵看成一维数组利用二分查找 val[m*column+n]=matrix[m][n]
		if(matrix.empty())return false;
		int row=matrix.size(),column=matrix[0].size();
		int left=0,right=row*column-1,mid;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(matrix[mid/column][mid%column]==target)
				return true;
			else if(matrix[mid/column][mid%column]>target)
				right=mid-1;
			else
				left=mid+1;
		}
		return false;
	}
};
int main()
{
	Solution mys;
	vector<vector<int> > matrix;//={{1,2,3},{4,5,6},{7,8,9}};
	cout<<mys.searchMatrix(matrix,5)<<endl;
	
	return 0;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
      if(!matrix) return 0;
		int row=matrixRowSize,column=matrixColSize;
		if(matrix[0][0]>target) return 0;
		//寻找位于第几行
		int left=0,right=row-1;
		int mid,target_row;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(matrix[mid][0]==target)
				return 1;
			else if(matrix[mid][0]<target)
				left=mid+1;
			else
				right=mid-1;
		}
		target_row=left-1;
		left=0,right=column-1;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(matrix[target_row][mid]==target)
				return 1;
			else if(matrix[target_row][mid]<target)
				left=mid+1;
			else
				right=mid-1;
		}
		return 0;
}



























