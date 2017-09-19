
/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

�������ɸ��㣬���ߵ�������

�㹲�ߣ���y=ax+b��֪�����б����ͬ���й�ͬ��������ֱ�߹��ߣ�������ֱ���ϵĵ㶼��һ��ֱ���ϣ���
1�������һ���㿪ʼ����Ϊ�����㣩�����α����������е㣬ֻ��б����ͬ���ɡ�
������
    1.����������б�ʲ����� ��a.x=b.x��б�������
	2.б�ʴ���  (b.y-a.y)/(b.x-a.x) 
	3.�ظ��ĵ� 
����һ��hash����ͳ�Ʋ�ͬб�ʵ�ֱ���ϵĵ���(б��ʹ��long double���ͱ�ʾ)
2��ʹ����򻯵ķ��ӷ�ĸ��ʾб��
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
double �������;
��double�����޸�Ϊlong double ����ͨ������
*/
    int maxPoints(vector<Point>& points) {
        int res=0;
		for(int i=0;i<points.size();i++)//ѡȡ������
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
	//����double�����洢�����ķ��ӡ���ĸ
	int maxPoints2(vector<Point>& points) {
        int res=0;
		for(int i=0;i<points.size();i++)//ѡȡ������
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

    

















