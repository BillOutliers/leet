
/*

矩阵顺时针旋转90度，找到旋转前后对应的行列坐标关系，然后一圈一圈的往里面旋转
    坐标旋转对应的关系：坐标(i,j)--->(j,n-1-i),

     --->    (i,j)--------
	 |	       |          |
     |      1  2  3       |
	 |                    |
(n-1-j,i)-->4  5  6 <-(j,n-1-i)    n:矩阵的行列长
	 |                    |
	 |      7  8  9       |
	 |         |          |
	 ----(n-1-i,n-1-j) <- |
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
		for(int i=0;i<=n/2;i++)//row
		{
			for(int j=i;j<n-i;j++)//column
			{
				swap(matrix[i][j],matrix[j][n-i]);
				swap(matrix[n-i][n-j],matrix[n-j][i]);
				swap(matrix[i][j],matrix[n-i][n-j]);
			}
		}
    }
};
int main()
{
    Solution mys;
	vector<std::vector<int> > matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for(int i=0;i<matrix.size();i++)
	{
	    for(int j=0;j<matrix[i].size();j++)
		    cout<<matrix[i][j]<<"  ";
		cout<<endl;
	}
	cout<<endl;
	mys.rotate(matrix);
	for(int i=0;i<matrix.size();i++)
	{
	    for(int j=0;j<matrix[i].size();j++)
		    cout<<matrix[i][j]<<"  ";
		cout<<endl;
	}
	
		
    return 0;	
}











