// leetcode unique paths ii.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size();
	if(m==0)
		return 0;
	int n = obstacleGrid[0].size();
	if(n == 0)
		return 0;
	vector<vector<int>> paths(m,vector<int>(n,0));
	for(int j=0;j<n;j++)
	{
		if(!obstacleGrid[0][j])
			paths[0][j] = 1;
		else
			break;
	}
	for(int i=0;i<m;i++)
	{
		if(!obstacleGrid[i][0])
			paths[i][0] = 1;
		else
			break;
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(!obstacleGrid[i][j])
				paths[i][j] = paths[i-1][j]+paths[i][j-1];
		}
	}
	return paths[m-1][n-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[][3] = {0,0,0,
		0,1,0,
		0,0,0
	};
	vector<vector<int> > obstacleGrid;
	for(int i=0;i<3;i++)
	{
		vector<int> tmp;
		for(int j=0;j<3;j++)
			tmp.push_back(data[i][j]);
		obstacleGrid.push_back(tmp);
	}
	int res = uniquePathsWithObstacles(obstacleGrid);
	return 0;
}

