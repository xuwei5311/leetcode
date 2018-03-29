// leetcode minimum path sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int minPathSum(vector<vector<int> > &grid) {
	int m = grid.size();
	if(m == 0)
		return 0;
	int n = grid[0].size();
	if(n == 0)
		return 0;
	vector<vector<int> > sum(m,vector<int>(n,0));
	sum[0][0] = grid[0][0];
	for(int j=1;j<n;j++)
		sum[0][j] = sum[0][j-1]+grid[0][j];
	for(int i=1;i<m;i++)
		sum[i][0] = sum[i-1][0]+grid[i][0];
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			sum[i][j] = max(sum[i-1][j],sum[i][j-1])+grid[i][j];
		}
	}
	return sum[m-1][n-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

