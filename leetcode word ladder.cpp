// leetcode word ladder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;


int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	unordered_set<string> unvisited = dict;
	queue<string> Q;
	unvisited.erase(start);
	Q.push(start);
	int currentLevelNumber = 1;
	int level = 1;
	while(!Q.empty())
	{
		int nextLevelNumber = 0;
		while(currentLevelNumber--)
		{
			string p = Q.front();
            Q.pop();
			for(int i=0;i<p.length();i++)
			{
				for(int j=0;j<26;j++)
				{
					string temp = p;
					temp[i] = 'a'+j;
					if(temp == end)
					{
						return (level+1);
					}
					if(temp != p && unvisited.count(temp))
					{
						unvisited.erase(temp);
						Q.push(temp);
						nextLevelNumber++;
					}
				}
			}
		}
		currentLevelNumber = nextLevelNumber;
		level++;
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	ladderLength("a", "c",dict );
	return 0;
}

