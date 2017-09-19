
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  �����沨�����ʽ��ֵ
  ��������ջ������������ʱ����������ջ����ֵ���������ջ����һ���ջ�����Ǳ��ʽ��ֵ
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return -1;
		stack<int> st;
		int m=0,n=0;
		for(int i=0;i<tokens.size();i++)
		{
			if(tokens[i]=="+" && st.size()>1)
			{
				m=st.top();
				st.pop();
				n=st.top();
				st.pop();
				st.push(m+n);continue;
			}
			if(tokens[i]=="-" && st.size()>1)
			{
				m=st.top();
				st.pop();
				n=st.top();
				st.pop();
				st.push(n-m);continue;
			}
			if(tokens[i]=="*" && st.size()>1)
			{
				m=st.top();
				st.pop();
				n=st.top();
				st.pop();
				st.push(m*n);continue;
			}
			if(tokens[i]=="/" && st.size()>1)
			{
				m=st.top();
				st.pop();
				n=st.top();
				st.pop();
				st.push(n/m);continue;
			}
			st.push(atoi(tokens[i].c_str()));
		}
		return st.top();
    }
};


