
/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

使用两个栈，一个用来存储数字，另一个用来存储操作符与括号，
当遇到‘('时把计算结果入栈，当遇到')'时把计算结果出栈
*/


class Solution {
public:
    int calculate(string s) {
        stack<int> num,ops;
		int res=0,tmp=0,sign=1;
		for(int i=0;i<s.size();i++)
		{
			if(isdigit(s[i]))
				tmp=tmp*10 + s[i] - '0';
			else if(s[i]!=' ')
			{
				res+=sign*tmp;
				tmp=0;
				if(s[i]=='+') sign=1;
				if(s[i]=='-') sign=-1;
				if(s[i]=='(')
				{
					num.push(res);
					ops.push(sign);
					res=0;
					sign=1;
				}
				if(s[i]==')' && !ops.empty())
				{
					res=ops.top() * res + num.top();
					ops.pop();
					num.pop();
				}
			}
		}
		res+=sign*tmp;
		return res;
    }
};


