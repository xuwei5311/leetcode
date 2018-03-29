// leetcode unique paths.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
	if(m==0 || n==0)
		return 0;
	vector<vector<int>> paths(m,vector<int>(n,0));
	for(int j=0;j<n;j++)
		paths[0][j] = 1;
	for(int i=0;i<m;i++)
		paths[i][0] = 1;
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			paths[i][j] = paths[i-1][j]+paths[i][j-1];
		}
	}
	return paths[m-1][n-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a = uniquePaths(2, 3);
	return 0;
}

