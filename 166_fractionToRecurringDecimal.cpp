

/*
����������������Ϊ���Ų��֡��������֡�С�����֣�
�����������������λ��Ȼ��ȡ����ֵ������(int)a/b ����������,
a%b ��ʣ�ಿ�֣���ת��ΪС�����֡�
��������������Ľ��Ϊ����ѭ��С��������Ӳ��ֵ�����ÿ�γ�10��
��ȡһλ������һ���������ֿ�ʼÿ�γ����ĸ����ͬ��

ע����ֵ������
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0) return "";
		if(numerator==0) return "0";
		string res="";
		if(numerator<0 ^ denominator<0) res+="-";
		long long n = abs((long long) numerator);//��ֵ����
		long long d = abs((long long) denominator);
		// cout<<n<<endl;
		// cout<<d<<endl;
		res+=std::to_string(static_cast<long long int>(n/d));//��������
		long long r=n%d;
		if(r==0) return res;
		res+=".";
		map<long long,int> s;
		while(r!=0)
		{
			if(s.find(r)!=s.end())
			{
				res.insert(s[r],"(");
				res+=")";
				break;
			}
			s[r]=res.size();//�洢�ַ����ĵ�ǰ����
			r*=10;
			res+=std::to_string(static_cast<long long int>(r/d));
			r%=d;
		}
		return res;
    }
};

int main()
{
	Solution mys;
	int numerator=-1;
	int denominator=-2147483648;//��С���� ����Ϊ long long ����������
	cout<<mys.fractionToDecimal(numerator,denominator)<<endl;
	return 0;
}









