// leetcode longest consecutive sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int> &num) 
{
	unordered_set<int> table;
	int n = num.size();
	for(int i=0;i<n;i++)
		table.insert(num[i]);
	int result = 0;
	for(int i=0;i<n;i++)
	{
		if(table.find(num[i]) != table.end())
		{
			int count = 1;
			for(int j=num[i]+1;;j++)
			{
				if(table.find(j) != table.end())
				{
					count++;
					table.erase(j);
				}
				else
					break;
			}
			for(int j=num[i]-1;;j--)
			{
				if(table.find(j) != table.end())
				{
					count++;
					table.erase(j);
				}
				else
					break;
			}
			result = max(result,count);
		}
	}
	return result;
}
int main()
{
	return 0;
}

