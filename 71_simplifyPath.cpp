
/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*/



#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res,tmp;
		vector<string> stk;
		stringstream ss(path);
		while(getline(ss,tmp,'/'))
		{
			//cout<<tmp<<endl;
			if(tmp=="." || tmp=="")continue;
			if(tmp==".." && !stk.empty()) stk.pop_back();
			else if(tmp!="..") stk.push_back(tmp);
		}
		if(stk.empty()) return "/";
		for(int i=0;i<stk.size();i++)
			res+='/'+stk[i];
		return res;
    }
};
int main()
{
	Solution mys;
	string path="/..";
	cout<<mys.simplifyPath(path)<<endl;
	return 0;
}

