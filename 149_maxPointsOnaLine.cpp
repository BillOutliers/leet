
/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

给定若干个点，求共线的最多点数

点共线，由y=ax+b可知，如果斜率相同且有共同点则两条直线共线，即两条直线上的点都在一条直线上；‘
1：如果从一个点开始（作为公共点），依次遍历其他所有点，只需斜率相同即可。
分析：
    1.如果两个点的斜率不存在 即a.x=b.x，斜率无穷大
	2.斜率存在  (b.y-a.y)/(b.x-a.x) 
	3.重复的点 
采用一个hash表来统计不同斜率的直线上的点数(斜率使用long double类型表示)
2：使用最简化的分子分母表示斜率
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
//Definition for a point.
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
  };
 
class Solution {
public:
/*
Submission Result: Wrong Answer More Details 
Input:
[[0,0],[94911151,94911150],[94911152,94911151]]
Output:
3
Expected:
2
double 存在误差;
把double类型修改为long double 类型通过测试
*/
    int maxPoints(vector<Point>& points) {
        int res=0;
		for(int i=0;i<points.size();i++)//选取公共点
		{
			int samePoints=1;
			unordered_map<long double,int> m;
			for(int j=i+1;j<points.size();j++)
			{
				if(points[i].x==points[j].x && points[i].y==points[j].y)
					samePoints++;
				else if(points[i].x==points[j].x)
					m[INT_MAX]++;
				else
				{
					long double slopes =(long double)(points[j].y - points[i].y)/(long double)(points[j].x -points[i].x);
					m[slopes]++;
				}
			}
			int maxP=0;
			for(unordered_map<long double,int>::iterator it=m.begin();it!=m.end();it++)
				maxP=max(maxP,it->second);
			maxP+=samePoints;
			res=max(res,maxP);
		}
		return res;//6 ms
    }
	//避免double的误差，存储化简后的分子、分母
	int maxPoints2(vector<Point>& points) {
        int res=0;
		for(int i=0;i<points.size();i++)//选取公共点
		{
			int samePoints=1,vertical=0;
			map<pair<int,int>,int> m;
			for(int j=i+1;j<points.size();j++)
			{
				if(points[i].x==points[j].x && points[i].y==points[j].y)
					samePoints++;
				else if(points[i].x==points[j].x)
					vertical++;
				else
				{
					int dx=points[j].x-points[i].x;
					int dy=points[j].y-points[i].y;
					int r=gcd(dx,dy);
					m[{dx/r,dy/r}]++;
				}	
			}
			int maxP=0;
			for(map<pair<int,int>,int>::iterator it=m.begin();it!=m.end();it++)
				maxP=max(maxP,it->second);
			maxP+=samePoints;
			res=max(res,maxP);
			res=max(res,samePoints+vertical);
		}
		return res;//9 ms
    }
	int gcd(int a,int b)
	{
		return (b==0) ? a : gcd(b,a%b);
	}
};

    

















