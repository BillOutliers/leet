
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together with 
x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

#include <stdio.h>
int maxArea(int* height, int heightSize)
{//‘À––≥¨ ±
	int max=0,i,j;
	int h_low=0;
	for(i=0;i<heightSize;i++)
		for(j=i+1;j<heightSize;j++)
		{
			h_low= height[i]>height[j] ? height[j] : height[i];
			max = max> (j-i)*h_low ? max : (j-i)*h_low;
		}
	return max;
}

/*
Start by evaluating the widest container, using the first and the last line.
All other possible containers are less wide, so to hold more water, they need
to be higher. Thus, after evaluating that widest container, skip lines at
both ends that don't support a higher height. Then evaluate that new 
container we arrived at. Repeat until there are no more possible containers 
left.
*/
int maxArea_f(int *height,int heightSize)
{
	int max=0,*i=height,*j=height+heightSize-1;
	int h,w;
	while(i<j)
	{
		h=*i < *j ? *i : *j;
		w=(j-i)*h;
		max = w>max ? w : max;
		while(*i <= h && i<j) i++;
		while(*j <= h && i<j) j--;
	}
	return max;
}
int main(int agrc,char **argv)
{
	int height[]={12,14,10};
	int heightSize=sizeof(height)/sizeof(int);
	printf("maxArea:%d\n",maxArea(height,heightSize));
	printf("maxArea:%d\n",maxArea_f(height,heightSize));
	return 0;
}