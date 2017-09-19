/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
/*
A=0110 0001	
C=0110 0011
G=0110 0111
T=0111 0100
����ÿʮ���ַ��Ƿ��ظ����֣����ÿ���ƶ�һ���ַ����б���ʱ�临�Ӷȣ�O(N^2)
�����ÿʮ���ַ��洢��hash���У�Ȼ���������ʱ�临�Ӷȣ�O(N)��
����ֻ���ĸ��ַ������ĸ��ַ�������bit����ͬ�����ĸ��ַ����±��룬����ASICC��ĺ�����bit
��ʾ��Ȼ��ʮ���ַ�ֻ��Ҫ30bit��ʹ��һ��int�Ϳ��Դ洢��Ȼ��洢��hash���С�
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
		int i=0,t=0;
		int n=s.size();
		cout<<n<<endl;
		if(n<=10) return res;
		while(i<9)
			t= t<<3 | (s[i++] & 7);
		unordered_map<int,int> m;
		while(i<n)
		{
			t= (t<<3 | (s[i] & 7)) & 0x3fffffff;
			m[t]++;
			if(m[t]==2)
			{
				res.push_back(s.substr(i-9,10));
			//	cout<<s.substr(i-9,10)<<endl;
			}
			i++;
		}
		return res;
    }
};
int main()
{
	Solution mys;
	string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> res=mys.findRepeatedDnaSequences(s);
	for(vector<string>::iterator it=res.begin();it!=res.end();it++)
		cout<<*it<<endl;
	
	return 0;
}


















