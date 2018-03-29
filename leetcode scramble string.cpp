// leetcode scramble string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

void reverse(string& s,int i,int j)
{
	while(i<j)
	{
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

const int MAXLENGTH = 100;
bool dp[MAXLENGTH][MAXLENGTH][MAXLENGTH];

bool isScramble(string s1, string s2) {
	if(s1.length() != s2.length())
		return false;
	if(s1.length() == 0)
		return true;
	int length = s1.length();
	for(int i=0;i<length;i++)
		for(int j=0;j<length;j++)
			for(int L=1;L<=length;L++)
				dp[i][j][L] = false;
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(s1[i] == s2[j])
				dp[i][j][1] = true;
		}
	}
	for(int L=2;L<=length;L++)
	{
		for(int i=0;i<=length-L;i++)
		{
			for(int j=0;j<=length-L;j++)
			{
				if(s1.substr(i,L) == s2.substr(j,L))
				{
					dp[i][j][L] = true;
					continue;
				}
				else
				{
					for(int k=1;k<L;k++)
					{
						if((dp[i][j][k] && dp[i+k][j+k][L-k])
							|| (dp[i][j+L-k][k] && dp[i+k][j][L-k]))
						{
							dp[i][j][L] = true;
							break;
						}
					}
				}
			}
		}
	}
	return dp[0][0][length];
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool result = isScramble("great", "rgeat");
	return 0;
}

