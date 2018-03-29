// leetcode n queens.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
using namespace std;

void solveNQueens(int n,int step,vector<vector<string> >& res,vector<vector<int>>& visited,vector<int>& path)
{
	if(step == n)
	{
		vector<string> tmp;
		for(int i=0;i<n;i++)
		{
			string str = "";
			for(int j=0;j<path[i];j++)
				str += ".";
			str += "Q";
			for(int j=path[i]+1;j<n;j++)
				str += ".";
			tmp.push_back(str);
		}
		res.push_back(tmp);
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(!visited[0][i] && !visited[1][i+step] && !visited[2][i-step+n-1])
		{
			path.push_back(i);
			visited[0][i] = visited[1][i+step] = visited[2][i-step+n-1] = 1;
			solveNQueens(n,step+1,res,visited,path);
			visited[0][i] = visited[1][i+step] = visited[2][i-step+n-1] = 0;
			path.pop_back();
		}
	}
}

vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > res;
	vector<vector<int>> visited(3,vector<int>(2*n-1,0));
	vector<int> path;
	solveNQueens(n,0,res,visited,path);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	solveNQueens(8);
	return 0;
}

