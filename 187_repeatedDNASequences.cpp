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
查找每十个字符是否重复出现，如果每次移动一个字符进行遍历时间复杂度：O(N^2)
如果把每十个字符存储在hash表中，然后遍历查找时间复杂度：O(N)；
由于只有四个字符，且四个字符后三个bit都不同，对四个字符重新编码，用其ASICC码的后三个bit
表示，然后十个字符只需要30bit，使用一个int就可以存储，然后存储到hash表中。
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


















