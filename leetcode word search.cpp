// leetcode word search.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

bool exist(vector<vector<char> > &board, string& word,vector<vector<bool> >& visited,int i,int j,int start)
{
	if(start == word.length())
		return true;
	if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || 
		visited[i][j] || board[i][j] != word[start])
		return false;
	visited[i][j] = true;
	bool res = exist(board,word,visited,i-1,j,start+1)
		|| exist(board,word,visited,i+1,j,start+1)
		|| exist(board,word,visited,i,j-1,start+1)
		|| exist(board,word,visited,i,j+1,start+1);
	visited[i][j] = false;
	return res;
}

bool exist(vector<vector<char> > &board, string word) {
	if(word.empty())
		return true;
	int m = board.size();
	if(m == 0)
		return false;
	int n = board[0].size();
	if(n == 0)
		return false;
	vector<vector<bool> > visited(m,vector<bool>(n,false));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(exist(board,word,visited,i,j,0))
				return true;
		}
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char data[3][4] = {'a','b','c','e',
	's','f','c','s',
	'a','d','e','e',};

	vector<vector<char> > board;
	for(int i=0;i<3;i++)
	{
		vector<char> temp(begin(data[i]),end(data[i]));
		board.push_back(temp);
	}
	bool r = exist(board,"abcced");
	return 0;
}

