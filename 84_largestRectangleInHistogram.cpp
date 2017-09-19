
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.
For example,
Given heights = [2,1,5,6,2,3],
return 10.
�󳤷��ε������Ҫ֪�����Ϳ���i��ֵΪ���ĳ����Σ���heights[i],��Ϊ��iΪ����㣬������չ����heights[j1]<height[i]ʱ��
������չ����heights[j2]<height[i]ʱ,j2-j1-1��Ϊ��ȡ�j1Ϊ��߽磬j2Ϊ�ұ߽硣
���Ѱ��ÿ��������ұ߽磺
1������ö�� ��ÿ���㶼����Ѱ��  ������̫��
2�����ö�̬�滮�������ظ����㣬���磺i<j, i����߽��Ѿ�����������ˣ���height[i]>=height[j]����������i����߽緶Χ����
   ����Ѱ��j����߽硣
3������ջ�� ���α������о����������Լ����Ըþ�����Ϊ�߶ȵľ�������������ڱ�����ʱ�����ǲ�֪�����滹��ʲô���ľ�������ô�죿
   û��ϵ������û��ȷ������ľ��Σ�ѹջ�������Ժ�����������Щ�Ѿ�����ȷ�����������ľ�����������Ҳû�ã���ջ
   
   �ο���http://www.cnblogs.com/boring09/p/4231906.html
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);//������������
		stack<int> index;
		int n=heights.size();
		int maxArea=0;
		int h,w;
		for(int i=0;i<heights.size();i++)
		{
			if(index.empty() || heights[index.top()]<heights[i])
				index.push(i);//����ջ�Ķ��ǵ�������
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



