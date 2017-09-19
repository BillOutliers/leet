

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.


*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
		for(int i=0;i<board.size();i++)
			for(int j=0;j<board[0].size();j++)
				if(dfs(board,word,i,j,0))
					return true;
		return false;
    }
	bool dfs(vector<vector<char>>& board,string word,int i,int j,int pos_word)
	{
		cout<<"pos_word:"<<pos_word<<endl;
		cout<<"word.length:"<<word.length()<<endl;
		if(pos_word==word.length()) return true;
		if(i >=board.size() || i<0 || j<0 || j>=board[0].size())
			return false;
		if(board[i][j]=='#')
			return false;
		if(board[i][j]!=word[pos_word])
			return false;
		char tmp=board[i][j];
		board[i][j]='#';
		cout<<"test"<<endl;
		bool res= dfs(board,word,i-1,j,pos_word+1)
		          || dfs(board,word,i+1,j,pos_word+1)
		          || dfs(board,word,i,j-1,pos_word+1)
		          || dfs(board,word,i,j+1,pos_word+1);
		board[i][j]=tmp;
		cout<<"res:"<<res<<endl;
		return res;
	}
};
int main()
{
	Solution mys;
	vector<vector<char>> board={{'a'}};
	string word="ab";
	cout<<mys.exist(board,word)<<endl;
	return 0;
}











