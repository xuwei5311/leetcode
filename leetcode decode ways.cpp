// leetcode decode ways.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

int dp[100] = {0};
int numDecodings(string s) {
	int n = s.length();
	if(n == 0)
		return 0;
	if(s[0] >= '1' && s[0] <= '9')
		dp[0] = 1;
	else
		dp[0] = 0;
	for(int i=1;i<n;i++)
	{
		if(s[i] >= '1' && s[i] <= '9')
			dp[i] += dp[i-1];
		if(s[i-1] >= '1' && s[i-1] <= '9')
		{
			int x = (s[i-1]-'0')*10+s[i]-'0';
			if(x >= 1 && x<= 26)
			{
				if(i >= 2)
					dp[i] += dp[i-2];
				else
					dp[i] += 1;
			}
		}
	}
	return dp[n-1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	numDecodings("10");
	return 0;
}

