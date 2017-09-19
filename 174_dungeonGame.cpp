/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned 
in the top-left room and must fight his way through the dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point 
drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these 
rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the 
optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
动态规划DP：
从坐下脚开始往右上角方向求算，求出到达每个格时需要的最少的能量

若给定的2D框图为m*n，可以采用m*n的数组point来保存在每一个方框上的最优解即
需要的最少能量，由于只能往下或者往右移动，所以每个方框的最优解只与其下方一个与
右边一个方框的最优解有关，状态转移方程为：
point[i][j]=max(1,min(point[i-1][j]-dungeon[i][j],point[i][j+1]-dungeon[i][j]));
最左侧一列与最下面一行需要单独处理边界条件。
此时空间复杂度为m*n，然而我们只需要求出最优解，每次的最优解只与其下与右方一个有关，
所以我们只需要m或n个大小的数组来存储子问题的解即可。为了更好的处理边界条件，采用
m+1或n+1来存储，由于2D方框中为int型，防止数值溢出与方便边界计算，采用long型来处理。
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP2(vector<vector<int>>& dungeon) {//72ms
		int row=dungeon.size(),column=dungeon[0].size();
        vector<int> point(column,0);
		point[column-1]=max(1,1-dungeon[row-1][column-1]);
		for(int i=column-2;i>=0;i--)
			point[i]=max(1,point[i+1]-dungeon[row-1][i]);
		for(int i=row-2;i>=0;i--)
		{
			point[column-1]=max(1,point[column-1]-dungeon[i][column-1]);
			for(int j=column-2;j>=0;j--)
			{
				point[j]=max(1,min(point[j]-dungeon[i][j],point[j+1]-dungeon[i][j]));
				cout<<point[j]<<endl;
			}
		}		
		return point[0];
    }
	 int calculateMinimumHP(vector<vector<int>>& dungeon) {//6ms
        vector<long> point(dungeon[0].size()+1,INT_MAX);
		point[dungeon[0].size()-1]=1;
		for(int i=dungeon.size()-1;i>=0;i--)
			for(int j=dungeon[0].size()-1;j>=0;j--)
			{
				long tmp = point[j]>point[j+1] ? point[j+1]-dungeon[i][j] : point[j]-dungeon[i][j];
				point[j]= tmp > 1 ? tmp : 1;
				//cout<<point[j]<<endl;
			}
		return point[0];
      
    }
};

int main()
{
	Solution mys;
	vector<vector<int> > dungeon={{0,-3,3}};
	cout<<mys.calculateMinimumHP(dungeon)<<endl;
	
	return 0;
}