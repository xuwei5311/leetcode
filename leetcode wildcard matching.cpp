// leetcode wildcard matching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

//直接递归超时
bool isMatch1(const char *s, const char *p,int i,int j,int m,int n)
{
	if(i==m && j==n)
		return true;
	if(i!=m && j==n)
		return false;
	if(p[j] == '*')
	{
		while(i <= m)
		{
			if(isMatch1(s,p,i,j+1,m,n))
				return true;
			i++;
		}
	}
	else if(p[j] == '?')
	{
		if(i == m)
			return false;
		else
			return isMatch1(s,p,i+1,j+1,m,n);
	}
	else
	{
		if(i == m || s[i] != p[j])
			return false;
		else
		{
			return isMatch1(s,p,i+1,j+1,m,n);
		}
	}
	return false;
}

bool isMatch1(const char *s, const char *p) {
	return isMatch1(s,p,0,0,strlen(s),strlen(p));
}

//动态规划
bool isMatch(const char *s, const char *p) {
	int m = strlen(s);
	int n = strlen(p);
	vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
	dp[0][0] = true;
	for(int j=1;j<=n;j++)
	{
		for(int i=0;i<=m;i++)
		{
			switch(p[j-1])
			{
			case '*':
				{
					for(int k=0;k<=i;k++)
					{
						if(dp[k][j-1])
						{
							dp[i][j] = true;
							break;
						}
					}
					break;
				}
			case '?':
				{
					dp[i][j] = ((i>=1) && dp[i-1][j-1]);
					break;
				}
			default:
				{
					dp[i][j] = ((i>=1) && (s[i-1] == p[j-1]) && dp[i-1][j-1]);
					break;
				}
			}
		}
	}
	return dp[m][n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool res = isMatch("ab", "?*");
	return 0;
}

