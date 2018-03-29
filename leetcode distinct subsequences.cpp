// leetcode distinct subsequences.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

static const int MAXLENTH = 1000;
int dp[MAXLENTH][MAXLENTH] = {0};
int numDistinct(string S, string T) 
{
	int m = S.length();
	int n = T.length();
	if(m < n) 
		return 0;
	int count = 0;
	for(int i=0;i<m;i++)
	{
		if(S[i] == T[0])
		{
			count++;
		}
        dp[i][0] = count;
	}
	for(int i=0;i<n;i++)
	{
		if(S[i] == T[i])
			dp[i][i] = 1;
		else
			break;
	}
	for(int i=2;i<m;i++)
	{
		for(int j=1;j<i && j<n;j++)
		{
			if(S[i] == T[j])
			{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[m-1][n-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	numDistinct("aabb", "aab");
	return 0;
}

