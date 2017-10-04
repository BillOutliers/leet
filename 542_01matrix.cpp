
/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return matrix;
        int m=matrix.size(),n=matrix[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        	for(int j=0;j<n;j++)
        		if(matrix[i][j]==0)
        			q.push(make_pair(i,j));
        		else
        			matrix[i][j]=m+n;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
		while(!q.empty()){
			pair<int,int> tmp=q.front();
			q.pop();
			for(int k=0;k<dir.size();k++){
				int r=dir[k].first + tmp.first;
				int c=dir[k].second + tmp.second;
				if(r>=0 && r<m && c>=0 && c<n && (matrix[r][c]>=matrix[tmp.first][tmp.second]+1)){
					matrix[r][c]=matrix[tmp.first][tmp.second]+1;
					q.push(make_pair(r,c));
				}
			}
		}
		return matrix;
    }
};
