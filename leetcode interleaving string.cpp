// leetcode interleaving string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;
bool dp[100][100];
bool isInterleave(string s1, string s2, string s3) {
	int m = s1.length();
	int n = s2.length();
	if(s3.length() != m+n)
		return false;
	dp[0][0] = true;
	for(int j=1;j<=n;j++)
	{
		if(s3.substr(0,j) != s2.substr(0,j))
			dp[0][j] = false;
		else
			dp[0][j] = true;
	}
	for(int i=1;i<=m;i++)
	{
		if(s3.substr(0,i) != s1.substr(0,i))
			dp[i][0] = false;
		else
			dp[i][0] = true;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				if(s3[i+j-1] != s1[i-1])
					dp[i][j] = false;
				else
					dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
			}
			else
			{
				if(s3[i+j-1] == s1[i-1])
					dp[i][j] = dp[i-1][j];
				else if(s3[i+j-1] == s2[j-1])
					dp[i][j] = dp[i][j-1];
				else
					dp[i][j] = false;
			}
		}
	}
	return dp[m][n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	isInterleave("aabd", "abdc", "aabdbadc");
	return 0;
}

