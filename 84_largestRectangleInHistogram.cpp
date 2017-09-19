
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.
For example,
Given heights = [2,1,5,6,2,3],
return 10.
求长方形的面积需要知道长和宽，第i个值为长的长方形，长heights[i],宽为以i为切入点，向左扩展，当heights[j1]<height[i]时，
向右扩展，当heights[j2]<height[i]时,j2-j1-1即为宽度。j1为左边界，j2为右边界。
如何寻找每个点的左右边界：
1：暴力枚举 对每个点都进行寻找  计算量太大
2：利用动态规划，避免重复计算，例如：i<j, i的左边界已经求出并保存了，且height[i]>=height[j]，可以跳过i的左边界范围继续
   向左寻找j的左边界。
3：辅助栈法 依次遍历所有矩形条，尝试计算以该矩形条为高度的矩形面积。但是在遍历的时候我们不知道后面还有什么样的矩形条怎么办？
   没关系，对于没法确定面积的矩形，压栈，留着以后处理，而对于那些已经可以确定计算出面积的矩形条，留着也没用，弹栈
   
   参考：http://www.cnblogs.com/boring09/p/4231906.html
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);//添加虚拟矩形条
		stack<int> index;
		int n=heights.size();
		int maxArea=0;
		int h,w;
		for(int i=0;i<heights.size();i++)
		{
			if(index.empty() || heights[index.top()]<heights[i])
				index.push(i);//进入栈的都是递增序列
			else
			{
				while(!index.empty() && heights[i]<=heights[index.top()])
				{
					h=heights[index.top()];
					index.pop();
					w= index.empty() ? i : i-index.top()-1;
					maxArea = max(maxArea,h*w);
				}
				index.push(i);
			}
		}
		return maxArea;
    }
};



