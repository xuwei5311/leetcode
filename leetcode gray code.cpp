// leetcode gray code.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

vector<int> dp[20];
vector<int> grayCode(int n) {
	for(int i=1;i<=n;i++)
	{
		int p = dp[i-1].size();
		for(int j=0;j<p;j++)
			dp[i].push_back(dp[i-1][j]);
		for(int j=p-1;j>=0;j--)
			dp[i].push_back(dp[i-1][j] + (1<<(i-1)));
	}
	return dp[n];
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

