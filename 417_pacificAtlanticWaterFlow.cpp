/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
对于矩阵中能够到达pacific的元素大于或等于其向上或向左的元素值，水才能流动，只要对第一行第一列进行dfs(如果水能够流动继续往四个方向访问)访问即可，能够
流到边界的进行标记；
对于矩阵中能够到达atlantic的元素大于或等于其向下或向右的元素值，水才能流动，只要对最后一行最后一列进行dfs访问即可，能够
流到边界的进行标记；
使用一个状态数组对矩阵的每个元素进行标记，判断能否达到边缘，如果达到pacific方向访问过记为1，达到atlantic标记为2,
如果为3表明该元素能够达到两个大洋。
*/

class Solution {
public: 
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    	 vector<pair<int,int>> res;
        if(matrix.empty()) return res;
        int m=matrix.size(),n=matrix[0].size();
         vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
        	dfs(res,visited,matrix,i,0,-1,1);
        	dfs(res,visited,matrix,i,n-1,-1,2);
        }
        for(int i=0;i<n;i++){
        	dfs(res,visited,matrix,0,i,-1,1);
        	dfs(res,visited,matrix,m-1,i,-1,2);
        }
        return res;
    }
    void dfs(vector<pair<int,int>>& res,vector<vector<int>>& visited,vector<vector<int>>& matrix,int x,int y,int pre,int preVal){
    	if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]<pre || (visited[x][y] & preVal) ==preVal)
    		return;
    	visited[x][y] |=preVal;
    	if(visited[x][y]==3) res.push_back({x,y});
    	dfs(res,visited,matrix,x-1,y,matrix[x][y],visited[x][y]);
    	dfs(res,visited,matrix,x+1,y,matrix[x][y],visited[x][y]);
    	dfs(res,visited,matrix,x,y-1,matrix[x][y],visited[x][y]);
    	dfs(res,visited,matrix,x,y+1,matrix[x][y],visited[x][y]);
    }
};