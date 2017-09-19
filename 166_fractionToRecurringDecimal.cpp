

/*
两个数相除，结果分为符号部分、整数部分、小数部分；
先求整数部分与符号位，然后取绝对值，例如(int)a/b 是整数部分,
a%b 是剩余部分，来转化为小数部分。
如果两个数相除后的结果为无限循环小数，则分子部分的数字每次乘10来
求取一位数，从一个非零数字开始每次除完分母都相同。

注意数值的提升
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
		long long n = abs((long long) numerator);//数值提升
		long long d = abs((long long) denominator);
		// cout<<n<<endl;
		// cout<<d<<endl;
		res+=std::to_string(static_cast<long long int>(n/d));//整数部分
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
			s[r]=res.size();//存储字符串的当前长度
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
	int denominator=-2147483648;//最小负数 提升为 long long 类型来处理
	cout<<mys.fractionToDecimal(numerator,denominator)<<endl;
	return 0;
}









