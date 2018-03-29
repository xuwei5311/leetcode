// leetcode edit distance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) {
	if(word1.length() > word2.length())
		swap(word1,word2);
	int m = word1.length();
	int n = word2.length();
	vector<vector<int>> distances(m+1,vector<int>(n+1,0));
	for(int j=1;j<=n;j++)
		distances[0][j] = j;
	for(int i=0;i<=m;i++)
		distances[i][0] = i;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int sig = (word1[i-1] == word2[j-1])? 0:1;
			distances[i][j] = min(distances[i-1][j]+1,min(distances[i-1][j-1]+sig,distances[i][j-1]+1));
		}
	}
	return distances[m][n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = minDistance("", "adcde");
	return 0;
}

