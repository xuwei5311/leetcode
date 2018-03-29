// leetcode triangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle) 
{
	vector<vector<int> > f = triangle;
	int m = triangle.size();
	if(m == 0)
		return 0;
	for(int i=m-2;i>=0;i--)
	{
		int n = triangle[i].size();
		if(n == 0)
			return 0;
		for(int j=0;j<=i;j++)
		{
			f[i][j] = triangle[i][j] + min(f[i+1][j],f[i+1][j+1]);
		}
	}
	return f[0][0];
}

int main()
{
	return 0;
}

