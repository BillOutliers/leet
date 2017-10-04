/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
        	for(int j=0;j<grid[0].size();j++){
        		if(grid[i][j]=='1'){
        			cnt++;
        			dfs(i,j,grid);
        			cout<<"hello"<<endl;
        		}
        	}
        }
        return cnt;
    }
    void dfs(int i,int j,vector<vector<char>> &grid){
    	if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1') return;
    	grid[i][j]='0';
    	dfs(i-1,j,grid);
    	dfs(i,j-1,grid);
    	dfs(i,j+1,grid);
    	dfs(i+1,j,grid);
    }
};
int main(){
	Solution mys;
	char tmp[]="1011011";
	std::vector<char> v(tmp,tmp+strlen(tmp));
	vector<vector<char> > grid;
	grid.push_back(v);
	cout<<mys.numIslands(grid)<<endl;
	return 0;
}

