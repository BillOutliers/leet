/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

对字符串中的每个操作符合进行最后运算，即先求出该符号左右两边的数值。
通过迭代所有的符号得到不同的组合。
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
		int size=input.size();
		for(int i=0;i<size;i++)
		{
			char cur=input[i];
			if(cur=='+' || cur=='-' || cur=='*')
			{
				vector<int> resL=diffWaysToCompute(input.substr(0,i));
				vector<int> resR=diffWaysToCompute(input.substr(i+1));
				for(int j=0;j<resL.size();j++)
					for(int k=0;k<resR.size();k++)
					{
						if(cur=='+')
							res.push_back(resL[j]+resR[k]);
						else if(cur=='-')
							res.push_back(resL[j]-resR[k]);
						else
							res.push_back(resL[j]*resR[k]);
					}
			}
		}
		if(res.empty())
			res.push_back(atoi(input.c_str()));
		return res;
    }
};

